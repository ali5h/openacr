// Copyright (C) 2023-2024 AlgoRND
// Copyright (C) 2023 Astra
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
// Target: atf_cov (exe) -- Line coverage
// Exceptions: yes
// Header: include/atf_cov.h
//

#include "include/algo.h"
#include "include/gen/atf_cov_gen.h"
#include "include/gen/atf_cov_gen.inl.h"

namespace atf_cov { // update-hdr
    // Dear human:
    //     Text from here to the closing curly brace was produced by scanning
    //     source files. Editing this text is futile.
    //     To refresh the contents of this section, run 'update-hdr'.
    //     To convert this section to a hand-written section, remove the word 'update-hdr' from namespace line.

    // -------------------------------------------------------------------
    // cpp/atf_cov/atf_cov.cpp
    //
    void MergeCovline(dev::Covline &covline_in);
    void RunGcov(strptr covdir);
    void WriteCovSsim();
    void ComputeCoverage();
    void GenerateSsimReport();
    void GenerateTxtReport();
    void Summary();
    void XmlIndent(algo::cstring &out, strptr text, int indent);
    void GenerateCoberturaReport();
    void Main_Check();
    void Main_Capture();
    void SaveCov();
    void Main();
}
