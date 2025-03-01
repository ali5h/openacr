## src_hdr - Internals


### Table Of Contents
<a href="#table-of-contents"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Toc -->
* [Description](#description)
* [Sources](#sources)
* [Dependencies](#dependencies)
* [In Memory DB](#in-memory-db)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Toc -->

### Description
<a href="#description"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Description -->
for usage, see [src_hdr - Manage source copyright+license header in source files and scripts](/txt/exe/src_hdr/README.md)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Description -->

### Sources
<a href="#sources"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Sources -->
The source code license is GPL
The following source files are part of this tool:

|Source File|Comment|
|---|---|
|[cpp/gen/src_hdr_gen.cpp](/cpp/gen/src_hdr_gen.cpp)||
|[cpp/src_hdr/hdr.cpp](/cpp/src_hdr/hdr.cpp)||
|[include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)||
|[include/gen/src_hdr_gen.inl.h](/include/gen/src_hdr_gen.inl.h)||

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Sources -->

### Dependencies
<a href="#dependencies"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Dependencies -->
The build target depends on the following libraries
|Target|Comment|
|---|---|
|[algo_lib](/txt/lib/algo_lib/README.md)|Support library for all executables|
|[lib_git](/txt/lib/lib_git/README.md)|Helpful git wrappers|

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Dependencies -->

### In Memory DB
<a href="#in-memory-db"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Imdb -->
`src_hdr` generated code creates the tables below.
All allocations are done through global `src_hdr::_db` [src_hdr.FDb](#src_hdr-fdb) structure
|Ctype|Ssimfile|Create|Access|
|---|---|---|---|
|[src_hdr.FCopyline](#src_hdr-fcopyline)||FDb.fcopyline (Tpool)|ind_fcopyline (Thash, hash field fcopyline)|
|[src_hdr.FCopyright](#src_hdr-fcopyright)|[dev.copyright](/txt/ssimdb/dev/copyright.md)|FDb.copyright (Lary)|copyright (Lary, by rowid)|c_dflt_copyright (Ptr)|ind_copyright (Thash, hash field copyright)|bh_copyright (Bheap, sort field sortkey)|
|[src_hdr.FDb](#src_hdr-fdb)||FDb._db (Global)|
|[src_hdr.FLicense](#src_hdr-flicense)|[dev.license](/txt/ssimdb/dev/license.md)|FDb.license (Lary)|license (Lary, by rowid)|ind_license (Thash, hash field license)|
||||FNs.p_license (Upptr)|
||||FScriptfile.p_license (Upptr)|
||||FSrc.p_license (Upptr)|
|[src_hdr.FNs](#src_hdr-fns)|[dmmeta.ns](/txt/ssimdb/dmmeta/ns.md)|FDb.ns (Lary)|ns (Lary, by rowid)|ind_ns (Thash, hash field ns)|
||||FTarget.p_ns (Upptr)|
|[src_hdr.FNsx](#src_hdr-fnsx)|[dmmeta.nsx](/txt/ssimdb/dmmeta/nsx.md)|FDb.nsx (Lary)|nsx (Lary, by rowid)|
||||FNs.c_nsx (Ptr)|
|[src_hdr.FScriptfile](#src_hdr-fscriptfile)|[dev.scriptfile](/txt/ssimdb/dev/scriptfile.md)|FDb.scriptfile (Lary)|scriptfile (Lary, by rowid)|
|[src_hdr.FSrc](#src_hdr-fsrc)||
|[src_hdr.FTarget](#src_hdr-ftarget)|[dev.target](/txt/ssimdb/dev/target.md)|FDb.target (Lary)|target (Lary, by rowid)|ind_target (Thash, hash field target)|
||||FTargsrc.p_target (Upptr)|
|[src_hdr.FTargsrc](#src_hdr-ftargsrc)|[dev.targsrc](/txt/ssimdb/dev/targsrc.md)|FDb.targsrc (Lary)|targsrc (Lary, by rowid)|
||||FSrc.p_targsrc (Upptr)|
||||FTarget.c_targsrc (Ptrary)|

#### src_hdr.FCopyline - 
<a href="#src_hdr-fcopyline"></a>

#### src_hdr.FCopyline Fields
<a href="#src_hdr-fcopyline-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FCopyline.fcopyline|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||

#### Struct FCopyline
<a href="#struct-fcopyline"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FCopyline { // src_hdr.FCopyline
    algo::cstring         fcopyline;            //
    src_hdr::FCopyline*   fcopyline_next;       // Pointer to next free element int tpool
    src_hdr::FCopyline*   ind_fcopyline_next;   // hash next
    // func:src_hdr.FCopyline..AssignOp
    inline src_hdr::FCopyline& operator =(const src_hdr::FCopyline &rhs) = delete;
    // func:src_hdr.FCopyline..CopyCtor
    inline               FCopyline(const src_hdr::FCopyline &rhs) = delete;
private:
    // func:src_hdr.FCopyline..Ctor
    inline               FCopyline() __attribute__((nothrow));
    // func:src_hdr.FCopyline..Dtor
    inline               ~FCopyline() __attribute__((nothrow));
    friend src_hdr::FCopyline&  fcopyline_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FCopyline*  fcopyline_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 fcopyline_Delete(src_hdr::FCopyline &row) __attribute__((nothrow));
};
```

#### src_hdr.FCopyright - Copyrighting entity
<a href="#src_hdr-fcopyright"></a>

#### src_hdr.FCopyright Fields
<a href="#src_hdr-fcopyright-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FCopyright.base|[dev.Copyright](/txt/ssimdb/dev/copyright.md)|[Base](/txt/ssimdb/dev/copyright.md)|||
|src_hdr.FCopyright.years|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FCopyright.sortkey|i32|[Val](/txt/exe/amc/reftypes.md#val)|||

#### Struct FCopyright
<a href="#struct-fcopyright"></a>
*Note:* field ``src_hdr.FCopyright.base`` has reftype ``base`` so the fields of [dev.Copyright](/txt/ssimdb/dev/copyright.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FCopyright { // src_hdr.FCopyright
    algo::Smallstr50       copyright;            //
    bool                   dflt;                 //   false
    algo::Comment          comment;              //
    algo::cstring          years;                //
    i32                    sortkey;              //   0
    src_hdr::FCopyright*   ind_copyright_next;   // hash next
    i32                    bh_copyright_idx;     // index in heap; -1 means not-in-heap
    // func:src_hdr.FCopyright..AssignOp
    inline src_hdr::FCopyright& operator =(const src_hdr::FCopyright &rhs) = delete;
    // func:src_hdr.FCopyright..CopyCtor
    inline               FCopyright(const src_hdr::FCopyright &rhs) = delete;
private:
    // func:src_hdr.FCopyright..Ctor
    inline               FCopyright() __attribute__((nothrow));
    // func:src_hdr.FCopyright..Dtor
    inline               ~FCopyright() __attribute__((nothrow));
    friend src_hdr::FCopyright& copyright_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FCopyright* copyright_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 copyright_RemoveAll() __attribute__((nothrow));
    friend void                 copyright_RemoveLast() __attribute__((nothrow));
};
```

#### src_hdr.FDb - In-memory database for src_hdr
<a href="#src_hdr-fdb"></a>

#### src_hdr.FDb Fields
<a href="#src_hdr-fdb-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FDb._db|[src_hdr.FDb](/txt/exe/src_hdr/internals.md#src_hdr-fdb)|[Global](/txt/exe/amc/reftypes.md#global)|||
|src_hdr.FDb.cmdline|[command.src_hdr](/txt/protocol/command/README.md#command-src_hdr)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FDb.targsrc|[src_hdr.FTargsrc](/txt/exe/src_hdr/internals.md#src_hdr-ftargsrc)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.ns|[src_hdr.FNs](/txt/exe/src_hdr/internals.md#src_hdr-fns)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.ind_ns|[src_hdr.FNs](/txt/exe/src_hdr/internals.md#src_hdr-fns)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|src_hdr.FDb.nsx|[src_hdr.FNsx](/txt/exe/src_hdr/internals.md#src_hdr-fnsx)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.license|[src_hdr.FLicense](/txt/exe/src_hdr/internals.md#src_hdr-flicense)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.ind_license|[src_hdr.FLicense](/txt/exe/src_hdr/internals.md#src_hdr-flicense)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|src_hdr.FDb.target|[src_hdr.FTarget](/txt/exe/src_hdr/internals.md#src_hdr-ftarget)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.ind_target|[src_hdr.FTarget](/txt/exe/src_hdr/internals.md#src_hdr-ftarget)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|src_hdr.FDb.scriptfile|[src_hdr.FScriptfile](/txt/exe/src_hdr/internals.md#src_hdr-fscriptfile)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.fcopyline|[src_hdr.FCopyline](/txt/exe/src_hdr/internals.md#src_hdr-fcopyline)|[Tpool](/txt/exe/amc/reftypes.md#tpool)|||
|src_hdr.FDb.ind_fcopyline|[src_hdr.FCopyline](/txt/exe/src_hdr/internals.md#src_hdr-fcopyline)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|src_hdr.FDb.copyright|[src_hdr.FCopyright](/txt/exe/src_hdr/internals.md#src_hdr-fcopyright)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|src_hdr.FDb.c_dflt_copyright|[src_hdr.FCopyright](/txt/exe/src_hdr/internals.md#src_hdr-fcopyright)|[Ptr](/txt/exe/amc/reftypes.md#ptr)|||
|src_hdr.FDb.ind_copyright|[src_hdr.FCopyright](/txt/exe/src_hdr/internals.md#src_hdr-fcopyright)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|src_hdr.FDb.bh_copyright|[src_hdr.FCopyright](/txt/exe/src_hdr/internals.md#src_hdr-fcopyright)|[Bheap](/txt/exe/amc/reftypes.md#bheap)|||

#### Struct FDb
<a href="#struct-fdb"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FDb { // src_hdr.FDb: In-memory database for src_hdr
    command::src_hdr        cmdline;                       //
    src_hdr::FTargsrc*      targsrc_lary[32];              // level array
    i32                     targsrc_n;                     // number of elements in array
    src_hdr::FNs*           ns_lary[32];                   // level array
    i32                     ns_n;                          // number of elements in array
    src_hdr::FNs**          ind_ns_buckets_elems;          // pointer to bucket array
    i32                     ind_ns_buckets_n;              // number of elements in bucket array
    i32                     ind_ns_n;                      // number of elements in the hash table
    src_hdr::FNsx*          nsx_lary[32];                  // level array
    i32                     nsx_n;                         // number of elements in array
    src_hdr::FLicense*      license_lary[32];              // level array
    i32                     license_n;                     // number of elements in array
    src_hdr::FLicense**     ind_license_buckets_elems;     // pointer to bucket array
    i32                     ind_license_buckets_n;         // number of elements in bucket array
    i32                     ind_license_n;                 // number of elements in the hash table
    src_hdr::FTarget*       target_lary[32];               // level array
    i32                     target_n;                      // number of elements in array
    src_hdr::FTarget**      ind_target_buckets_elems;      // pointer to bucket array
    i32                     ind_target_buckets_n;          // number of elements in bucket array
    i32                     ind_target_n;                  // number of elements in the hash table
    src_hdr::FScriptfile*   scriptfile_lary[32];           // level array
    i32                     scriptfile_n;                  // number of elements in array
    u64                     fcopyline_blocksize;           // # bytes per block
    src_hdr::FCopyline*     fcopyline_free;                //
    src_hdr::FCopyline**    ind_fcopyline_buckets_elems;   // pointer to bucket array
    i32                     ind_fcopyline_buckets_n;       // number of elements in bucket array
    i32                     ind_fcopyline_n;               // number of elements in the hash table
    src_hdr::FCopyright*    copyright_lary[32];            // level array
    i32                     copyright_n;                   // number of elements in array
    src_hdr::FCopyright*    c_dflt_copyright;              // optional pointer
    src_hdr::FCopyright**   ind_copyright_buckets_elems;   // pointer to bucket array
    i32                     ind_copyright_buckets_n;       // number of elements in bucket array
    i32                     ind_copyright_n;               // number of elements in the hash table
    src_hdr::FCopyright**   bh_copyright_elems;            // binary heap by sortkey
    i32                     bh_copyright_n;                // number of elements in the heap
    i32                     bh_copyright_max;              // max elements in bh_copyright_elems
    src_hdr::trace          trace;                         //
};
```

#### src_hdr.FLicense - Source code license
<a href="#src_hdr-flicense"></a>

#### src_hdr.FLicense Fields
<a href="#src_hdr-flicense-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FLicense.base|[dev.License](/txt/ssimdb/dev/license.md)|[Base](/txt/ssimdb/dev/license.md)|||
|src_hdr.FLicense.text|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||

#### Struct FLicense
<a href="#struct-flicense"></a>
*Note:* field ``src_hdr.FLicense.base`` has reftype ``base`` so the fields of [dev.License](/txt/ssimdb/dev/license.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FLicense { // src_hdr.FLicense
    src_hdr::FLicense*   ind_license_next;   // hash next
    algo::Smallstr50     license;            //
    algo::Comment        comment;            //
    algo::cstring        text;               //
    // func:src_hdr.FLicense..AssignOp
    inline src_hdr::FLicense& operator =(const src_hdr::FLicense &rhs) = delete;
    // func:src_hdr.FLicense..CopyCtor
    inline               FLicense(const src_hdr::FLicense &rhs) = delete;
private:
    // func:src_hdr.FLicense..Ctor
    inline               FLicense() __attribute__((nothrow));
    // func:src_hdr.FLicense..Dtor
    inline               ~FLicense() __attribute__((nothrow));
    friend src_hdr::FLicense&   license_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FLicense*   license_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 license_RemoveAll() __attribute__((nothrow));
    friend void                 license_RemoveLast() __attribute__((nothrow));
};
```

#### src_hdr.FNs - Namespace (for in-memory database, protocol, etc)
<a href="#src_hdr-fns"></a>

#### src_hdr.FNs Fields
<a href="#src_hdr-fns-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FNs.base|[dmmeta.Ns](/txt/ssimdb/dmmeta/ns.md)|[Base](/txt/ssimdb/dmmeta/ns.md)|||
|src_hdr.FNs.c_nsx|[src_hdr.FNsx](/txt/exe/src_hdr/internals.md#src_hdr-fnsx)|[Ptr](/txt/exe/amc/reftypes.md#ptr)|||
|src_hdr.FNs.p_license|[src_hdr.FLicense](/txt/exe/src_hdr/internals.md#src_hdr-flicense)|[Upptr](/txt/exe/amc/reftypes.md#upptr)|||

#### Struct FNs
<a href="#struct-fns"></a>
*Note:* field ``src_hdr.FNs.base`` has reftype ``base`` so the fields of [dmmeta.Ns](/txt/ssimdb/dmmeta/ns.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FNs { // src_hdr.FNs
    src_hdr::FNs*        ind_ns_next;   // hash next
    algo::Smallstr16     ns;            // Namespace name (primary key)
    algo::Smallstr50     nstype;        // Namespace type
    algo::Smallstr50     license;       // Associated license
    algo::Comment        comment;       //
    src_hdr::FNsx*       c_nsx;         // optional pointer
    src_hdr::FLicense*   p_license;     // reference to parent row
    // x-reference on src_hdr.FNs.c_nsx prevents copy
    // x-reference on src_hdr.FNs.p_license prevents copy
    // func:src_hdr.FNs..AssignOp
    inline src_hdr::FNs& operator =(const src_hdr::FNs &rhs) = delete;
    // x-reference on src_hdr.FNs.c_nsx prevents copy
    // x-reference on src_hdr.FNs.p_license prevents copy
    // func:src_hdr.FNs..CopyCtor
    inline               FNs(const src_hdr::FNs &rhs) = delete;
private:
    // func:src_hdr.FNs..Ctor
    inline               FNs() __attribute__((nothrow));
    // func:src_hdr.FNs..Dtor
    inline               ~FNs() __attribute__((nothrow));
    friend src_hdr::FNs&        ns_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FNs*        ns_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 ns_RemoveLast() __attribute__((nothrow));
};
```

#### src_hdr.FNsx - Control code-generation and exception handling options for process/library
<a href="#src_hdr-fnsx"></a>

#### src_hdr.FNsx Fields
<a href="#src_hdr-fnsx-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FNsx.base|[dmmeta.Nsx](/txt/ssimdb/dmmeta/nsx.md)|[Base](/txt/ssimdb/dmmeta/nsx.md)|||

#### Struct FNsx
<a href="#struct-fnsx"></a>
*Note:* field ``src_hdr.FNsx.base`` has reftype ``base`` so the fields of [dmmeta.Nsx](/txt/ssimdb/dmmeta/nsx.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FNsx { // src_hdr.FNsx
    algo::Smallstr16    ns;                    //
    bool                genthrow;              //   false
    bool                correct_getorcreate;   //   false
    algo::Smallstr100   pool;                  //
    bool                sortxref;              //   false
    bool                pack;                  //   false
    algo::Comment       comment;               //
    // func:src_hdr.FNsx..AssignOp
    inline src_hdr::FNsx& operator =(const src_hdr::FNsx &rhs) = delete;
    // func:src_hdr.FNsx..CopyCtor
    inline               FNsx(const src_hdr::FNsx &rhs) = delete;
private:
    // func:src_hdr.FNsx..Ctor
    inline               FNsx() __attribute__((nothrow));
    // func:src_hdr.FNsx..Dtor
    inline               ~FNsx() __attribute__((nothrow));
    friend src_hdr::FNsx&       nsx_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FNsx*       nsx_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 nsx_RemoveLast() __attribute__((nothrow));
};
```

#### src_hdr.FScriptfile - Known script file
<a href="#src_hdr-fscriptfile"></a>

#### src_hdr.FScriptfile Fields
<a href="#src_hdr-fscriptfile-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FScriptfile.base|[dev.Scriptfile](/txt/ssimdb/dev/scriptfile.md)|[Base](/txt/ssimdb/dev/scriptfile.md)|||
|src_hdr.FScriptfile.p_license|[src_hdr.FLicense](/txt/exe/src_hdr/internals.md#src_hdr-flicense)|[Upptr](/txt/exe/amc/reftypes.md#upptr)|||

#### Struct FScriptfile
<a href="#struct-fscriptfile"></a>
*Note:* field ``src_hdr.FScriptfile.base`` has reftype ``base`` so the fields of [dev.Scriptfile](/txt/ssimdb/dev/scriptfile.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FScriptfile { // src_hdr.FScriptfile
    algo::Smallstr200    gitfile;     //
    algo::Smallstr50     license;     //
    algo::Comment        comment;     //
    src_hdr::FLicense*   p_license;   // reference to parent row
private:
    // func:src_hdr.FScriptfile..Ctor
    inline               FScriptfile() __attribute__((nothrow));
    friend src_hdr::FScriptfile& scriptfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FScriptfile* scriptfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 scriptfile_RemoveAll() __attribute__((nothrow));
    friend void                 scriptfile_RemoveLast() __attribute__((nothrow));
};
```

#### src_hdr.FSrc - 
<a href="#src_hdr-fsrc"></a>

#### src_hdr.FSrc Fields
<a href="#src_hdr-fsrc-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FSrc.src|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)||Filename|
|src_hdr.FSrc.comment|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FSrc.cmtstring|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)||Comment string|
|src_hdr.FSrc.body|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FSrc.p_license|[src_hdr.FLicense](/txt/exe/src_hdr/internals.md#src_hdr-flicense)|[Upptr](/txt/exe/amc/reftypes.md#upptr)|||
|src_hdr.FSrc.p_targsrc|[src_hdr.FTargsrc](/txt/exe/src_hdr/internals.md#src_hdr-ftargsrc)|[Upptr](/txt/exe/amc/reftypes.md#upptr)||May be NULL|
|src_hdr.FSrc.text|[algo.strptr](/txt/protocol/algo/strptr.md)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FSrc.copyright|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FSrc.saw_target|bool|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FSrc.shebang|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)|||
|src_hdr.FSrc.contact_ice|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)||Contact information|

#### Struct FSrc
<a href="#struct-fsrc"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FSrc { // src_hdr.FSrc
    algo::cstring        src;           // Filename
    algo::cstring        comment;       //
    algo::cstring        cmtstring;     // Comment string
    algo::cstring        body;          //
    src_hdr::FLicense*   p_license;     // reference to parent row
    src_hdr::FTargsrc*   p_targsrc;     // reference to parent row
    algo::strptr         text;          //
    algo::cstring        copyright;     //
    bool                 saw_target;    //   false
    algo::cstring        shebang;       //
    algo::cstring        contact_ice;   // Contact information
    // func:src_hdr.FSrc..Ctor
    inline               FSrc() __attribute__((nothrow));
};
```

#### src_hdr.FTarget - Build target
<a href="#src_hdr-ftarget"></a>

#### src_hdr.FTarget Fields
<a href="#src_hdr-ftarget-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FTarget.base|[dev.Target](/txt/ssimdb/dev/target.md)|[Base](/txt/ssimdb/dev/target.md)|||
|src_hdr.FTarget.c_targsrc|[src_hdr.FTargsrc](/txt/exe/src_hdr/internals.md#src_hdr-ftargsrc)|[Ptrary](/txt/exe/amc/reftypes.md#ptrary)|||
|src_hdr.FTarget.p_ns|[src_hdr.FNs](/txt/exe/src_hdr/internals.md#src_hdr-fns)|[Upptr](/txt/exe/amc/reftypes.md#upptr)|||

#### Struct FTarget
<a href="#struct-ftarget"></a>
*Note:* field ``src_hdr.FTarget.base`` has reftype ``base`` so the fields of [dev.Target](/txt/ssimdb/dev/target.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FTarget { // src_hdr.FTarget
    src_hdr::FTarget*     ind_target_next;   // hash next
    algo::Smallstr16      target;            // Primary key - name of target
    src_hdr::FTargsrc**   c_targsrc_elems;   // array of pointers
    u32                   c_targsrc_n;       // array of pointers
    u32                   c_targsrc_max;     // capacity of allocated array
    src_hdr::FNs*         p_ns;              // reference to parent row
    // reftype Ptrary of src_hdr.FTarget.c_targsrc prohibits copy
    // x-reference on src_hdr.FTarget.p_ns prevents copy
    // func:src_hdr.FTarget..AssignOp
    inline src_hdr::FTarget& operator =(const src_hdr::FTarget &rhs) = delete;
    // reftype Ptrary of src_hdr.FTarget.c_targsrc prohibits copy
    // x-reference on src_hdr.FTarget.p_ns prevents copy
    // func:src_hdr.FTarget..CopyCtor
    inline               FTarget(const src_hdr::FTarget &rhs) = delete;
private:
    // func:src_hdr.FTarget..Ctor
    inline               FTarget() __attribute__((nothrow));
    // func:src_hdr.FTarget..Dtor
    inline               ~FTarget() __attribute__((nothrow));
    friend src_hdr::FTarget&    target_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FTarget*    target_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 target_RemoveAll() __attribute__((nothrow));
    friend void                 target_RemoveLast() __attribute__((nothrow));
};
```

#### src_hdr.FTargsrc - List of sources for target
<a href="#src_hdr-ftargsrc"></a>

#### src_hdr.FTargsrc Fields
<a href="#src_hdr-ftargsrc-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|src_hdr.FTargsrc.base|[dev.Targsrc](/txt/ssimdb/dev/targsrc.md)|[Base](/txt/ssimdb/dev/targsrc.md)|||
|src_hdr.FTargsrc.select|bool|[Val](/txt/exe/amc/reftypes.md#val)||Temporary flag|
|src_hdr.FTargsrc.p_target|[src_hdr.FTarget](/txt/exe/src_hdr/internals.md#src_hdr-ftarget)|[Upptr](/txt/exe/amc/reftypes.md#upptr)|||

#### Struct FTargsrc
<a href="#struct-ftargsrc"></a>
*Note:* field ``src_hdr.FTargsrc.base`` has reftype ``base`` so the fields of [dev.Targsrc](/txt/ssimdb/dev/targsrc.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/src_hdr_gen.h](/include/gen/src_hdr_gen.h)
```
struct FTargsrc { // src_hdr.FTargsrc
    algo::Smallstr100   targsrc;                   //
    algo::Comment       comment;                   //
    bool                select;                    //   false  Temporary flag
    src_hdr::FTarget*   p_target;                  // reference to parent row
    bool                target_c_targsrc_in_ary;   //   false  membership flag
    // x-reference on src_hdr.FTargsrc.p_target prevents copy
    // func:src_hdr.FTargsrc..AssignOp
    inline src_hdr::FTargsrc& operator =(const src_hdr::FTargsrc &rhs) = delete;
    // x-reference on src_hdr.FTargsrc.p_target prevents copy
    // func:src_hdr.FTargsrc..CopyCtor
    inline               FTargsrc(const src_hdr::FTargsrc &rhs) = delete;
private:
    // func:src_hdr.FTargsrc..Ctor
    inline               FTargsrc() __attribute__((nothrow));
    // func:src_hdr.FTargsrc..Dtor
    inline               ~FTargsrc() __attribute__((nothrow));
    friend src_hdr::FTargsrc&   targsrc_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_hdr::FTargsrc*   targsrc_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 targsrc_RemoveLast() __attribute__((nothrow));
};
```

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Imdb -->

