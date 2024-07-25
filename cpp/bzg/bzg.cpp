// Copyright (C) 2024 Astra
//
// License: GPL
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Target: bzg (exe)
// Exceptions: yes
// Source: cpp/bzg/bzg.cpp
//

#include "include/algo.h"
#include "include/algo.h"
#include "include/bzg.h"

void bzg::Main() {
    auto build = dev::Builddir_Concat_uname_compiler_cfg_arch(bzg::dev_uname_Linux,
                                                              dev_Compiler_compiler_bazel,
                                                              dev_Cfg_cfg_release,
                                                              dev_Arch_arch_x86_64);
    ind_beg(_db_tool_opt_curs,tool_opt,_db) {
        Regx_ReadSql(tool_opt.regx_opt,Pathcomp(tool_opt.tool_opt,"/LL"),true);
        Regx_ReadSql(tool_opt.regx_target,target_Get(tool_opt),true);
        tool_opt.select = Regx_Match(tool_opt.regx_opt,build);
    }ind_end;

    ind_beg(_db_targsyslib_curs, syslib, _db) if (uname_Get(syslib) == dev_uname_Linux) {
        zd_targsyslib_Insert(*syslib.p_ns, syslib);
    }ind_end;

    cstring out;
    algo_lib::Replscope R;
    algo::ListSep sep("\n");
    ind_beg(_db_ns_curs, ns, _db) if (!zd_targsrc_EmptyQ(ns)) {
        out << sep;
        Set(R, "$rule", ns.nstype == dmmeta_Nstype_nstype_exe ? "cc_binary" : "cc_library");
        Set(R, "$name", ns.ns);
        Ins(&R, out, "$rule(");
        Ins(&R, out, "    name = \"$name\",");

        Ins(&R, out, "    srcs = [");
        ind_beg(ns_zd_targsrc_curs, src, ns) {
            Set(R, "$src", src_Get(src));
            Ins(&R, out, "        \"$src\",");
        }ind_end;
        Ins(&R, out, "    ],");

        Ins(&R, out, "    copts = [");
        ind_beg(_db_tool_opt_curs, tool_opt, _db) if (tool_opt.select && opt_type_Get(tool_opt) == dev_opt_type_CC) {
            if (Regx_Match(tool_opt.regx_target,ns.ns)) {
                Set(R, "$opt", opt_Get(tool_opt));
                Ins(&R, out, "        \"$opt\",");
            }
        }ind_end;
        Ins(&R, out, "    ],");

        Ins(&R, out, "    linkopts = [");
        ind_beg(_db_tool_opt_curs, tool_opt, _db) if (tool_opt.select && opt_type_Get(tool_opt) == dev_opt_type_LINK) {
            if (Regx_Match(tool_opt.regx_target,ns.ns)) {
                Set(R, "$opt", opt_Get(tool_opt));
                Ins(&R, out, "        \"$opt\",");
            }
        }ind_end;
        ind_beg(ns_zd_targsyslib_curs, syslib, ns) {
            Set(R, "$lib", syslib_Get(syslib));
            Ins(&R, out, "        \"-l$lib\",");
        }ind_end;
        Ins(&R, out, "    ],");

        Ins(&R, out, "    deps = [");
        ind_beg(ns_zd_targdep_curs, dep, ns) {
            Set(R, "$dep", parent_Get(dep));
            Ins(&R, out, "        \":$dep\",");
        }ind_end;
        Ins(&R, out, "    ],");

        Ins(&R, out, ")");
    }ind_end;

    Ins(&R, out, R"bz(
genrule(
    name = "runner",
    outs = ["runner.sh"],
    cmd = """
echo 'cd $$(dirname $$(readlink -f BUILD))' >> $@
echo $(location atf_comp) -build:N -ood:N '$$@' >> $@
    """,
    tools = [":atf_comp"],
)

sh_test(
    name = "atf_comp_tests",
    srcs = ["runner.sh"],
    args = [
        "-compdir:$(BINDIR)",
    ],
    data = [
        ":BUILD",
    ],
))bz");

    if (_db.cmdline.write) {
        algo::SafeStringToFile(out, "BUILD");
    } else {
        prlog_(out);
    }
}
