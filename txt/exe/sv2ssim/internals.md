## sv2ssim - Internals


### Table Of Contents
<a href="#table-of-contents"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Toc -->
* [Description](#description)
* [Sources](#sources)
* [Dependencies](#dependencies)
* [In Memory DB](#in-memory-db)
* [Tests](#tests)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Toc -->

### Description
<a href="#description"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Description -->
for usage, see [sv2ssim - sv2ssim - Separated Value file processor](/txt/exe/sv2ssim/README.md)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Description -->

### Sources
<a href="#sources"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Sources -->
The source code license is GPL
The following source files are part of this tool:

|Source File|Comment|
|---|---|
|[cpp/gen/sv2ssim_gen.cpp](/cpp/gen/sv2ssim_gen.cpp)||
|[cpp/sv2ssim.cpp](/cpp/sv2ssim.cpp)||
|[include/gen/sv2ssim_gen.h](/include/gen/sv2ssim_gen.h)||
|[include/gen/sv2ssim_gen.inl.h](/include/gen/sv2ssim_gen.inl.h)||
|[include/sv2ssim.h](/include/sv2ssim.h)||

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Sources -->

### Dependencies
<a href="#dependencies"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Dependencies -->
The build target depends on the following libraries
|Target|Comment|
|---|---|
|[algo_lib](/txt/lib/algo_lib/README.md)|Support library for all executables|
|[lib_amcdb](/txt/lib/lib_amcdb/README.md)|Library used by amc|

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Dependencies -->

### In Memory DB
<a href="#in-memory-db"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Imdb -->
`sv2ssim` generated code creates the tables below.
All allocations are done through global `sv2ssim::_db` [sv2ssim.FDb](#sv2ssim-fdb) structure
|Ctype|Ssimfile|Create|Access|
|---|---|---|---|
|[sv2ssim.FBltin](#sv2ssim-fbltin)|[amcdb.bltin](/txt/ssimdb/amcdb/bltin.md)|FDb.bltin (Lary)|bltin (Lary, by rowid)|ind_bltin (Thash, hash field ctype)|
|[sv2ssim.FDb](#sv2ssim-fdb)||FDb._db (Global)|
|[sv2ssim.FField](#sv2ssim-ffield)||FDb.field (Lary)|field (Lary, by rowid)|ind_field (Thash, hash field name)|zd_selfield (Llist)|
|[sv2ssim.FSvtype](#sv2ssim-fsvtype)|[dmmeta.svtype](/txt/ssimdb/dmmeta/svtype.md)|FDb.svtype (Lary)|svtype (Lary, by rowid)|

#### sv2ssim.FBltin - Specify properties of a C built-in type
<a href="#sv2ssim-fbltin"></a>

#### sv2ssim.FBltin Fields
<a href="#sv2ssim-fbltin-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|sv2ssim.FBltin.base|[amcdb.Bltin](/txt/ssimdb/amcdb/bltin.md)|[Base](/txt/ssimdb/amcdb/bltin.md)|||

#### Struct FBltin
<a href="#struct-fbltin"></a>
*Note:* field ``sv2ssim.FBltin.base`` has reftype ``base`` so the fields of [amcdb.Bltin](/txt/ssimdb/amcdb/bltin.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/sv2ssim_gen.h](/include/gen/sv2ssim_gen.h)
```
struct FBltin { // sv2ssim.FBltin
    algo::Smallstr100   ctype;            //
    bool                likeu64;          //   false
    bool                bigendok;         //   false
    bool                issigned;         //   false
    algo::Comment       comment;          //
    sv2ssim::FBltin*    ind_bltin_next;   // hash next
    // func:sv2ssim.FBltin..AssignOp
    inline sv2ssim::FBltin& operator =(const sv2ssim::FBltin &rhs) = delete;
    // func:sv2ssim.FBltin..CopyCtor
    inline               FBltin(const sv2ssim::FBltin &rhs) = delete;
private:
    // func:sv2ssim.FBltin..Ctor
    inline               FBltin() __attribute__((nothrow));
    // func:sv2ssim.FBltin..Dtor
    inline               ~FBltin() __attribute__((nothrow));
    friend sv2ssim::FBltin&     bltin_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend sv2ssim::FBltin*     bltin_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 bltin_RemoveAll() __attribute__((nothrow));
    friend void                 bltin_RemoveLast() __attribute__((nothrow));
};
```

#### sv2ssim.FDb - In-memory database for sv2ssim
<a href="#sv2ssim-fdb"></a>

#### sv2ssim.FDb Fields
<a href="#sv2ssim-fdb-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|sv2ssim.FDb._db|[sv2ssim.FDb](/txt/exe/sv2ssim/internals.md#sv2ssim-fdb)|[Global](/txt/exe/amc/reftypes.md#global)|||
|sv2ssim.FDb.cmdline|[command.sv2ssim](/txt/protocol/command/README.md#command-sv2ssim)|[Val](/txt/exe/amc/reftypes.md#val)|||
|sv2ssim.FDb.field|[sv2ssim.FField](/txt/exe/sv2ssim/internals.md#sv2ssim-ffield)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|sv2ssim.FDb.linetok|[algo.cstring](/txt/protocol/algo/cstring.md)|[Tary](/txt/exe/amc/reftypes.md#tary)||Current line, tokenized|
|sv2ssim.FDb.n_wideline|i32|[Val](/txt/exe/amc/reftypes.md#val)|true|Number of lines wider than header|
|sv2ssim.FDb.svtype|[sv2ssim.FSvtype](/txt/exe/sv2ssim/internals.md#sv2ssim-fsvtype)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|sv2ssim.FDb.ind_field|[sv2ssim.FField](/txt/exe/sv2ssim/internals.md#sv2ssim-ffield)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|sv2ssim.FDb.zd_selfield|[sv2ssim.FField](/txt/exe/sv2ssim/internals.md#sv2ssim-ffield)|[Llist](/txt/exe/amc/reftypes.md#llist)|||
|sv2ssim.FDb.bltin|[sv2ssim.FBltin](/txt/exe/sv2ssim/internals.md#sv2ssim-fbltin)|[Lary](/txt/exe/amc/reftypes.md#lary)|||
|sv2ssim.FDb.ind_bltin|[sv2ssim.FBltin](/txt/exe/sv2ssim/internals.md#sv2ssim-fbltin)|[Thash](/txt/exe/amc/reftypes.md#thash)|||
|sv2ssim.FDb.cmt2fld_ok|bool|[Val](/txt/exe/amc/reftypes.md#val)|||

#### Struct FDb
<a href="#struct-fdb"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/sv2ssim_gen.h](/include/gen/sv2ssim_gen.h)
```
struct FDb { // sv2ssim.FDb: In-memory database for sv2ssim
    command::sv2ssim    cmdline;                   //
    sv2ssim::FField*    field_lary[32];            // level array
    i32                 field_n;                   // number of elements in array
    algo::cstring*      linetok_elems;             // pointer to elements
    u32                 linetok_n;                 // number of elements in array
    u32                 linetok_max;               // max. capacity of array before realloc
    i32                 n_wideline;                //   true  Number of lines wider than header
    sv2ssim::FSvtype*   svtype_lary[32];           // level array
    i32                 svtype_n;                  // number of elements in array
    sv2ssim::FField**   ind_field_buckets_elems;   // pointer to bucket array
    i32                 ind_field_buckets_n;       // number of elements in bucket array
    i32                 ind_field_n;               // number of elements in the hash table
    sv2ssim::FField*    zd_selfield_head;          // zero-terminated doubly linked list
    i32                 zd_selfield_n;             // zero-terminated doubly linked list
    sv2ssim::FField*    zd_selfield_tail;          // pointer to last element
    sv2ssim::FBltin*    bltin_lary[32];            // level array
    i32                 bltin_n;                   // number of elements in array
    sv2ssim::FBltin**   ind_bltin_buckets_elems;   // pointer to bucket array
    i32                 ind_bltin_buckets_n;       // number of elements in bucket array
    i32                 ind_bltin_n;               // number of elements in the hash table
    bool                cmt2fld_ok;                //   false
    sv2ssim::trace      trace;                     //
};
```

#### sv2ssim.FField - 
<a href="#sv2ssim-ffield"></a>

#### sv2ssim.FField Fields
<a href="#sv2ssim-ffield-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|sv2ssim.FField.name|[algo.cstring](/txt/protocol/algo/cstring.md)|[Val](/txt/exe/amc/reftypes.md#val)||Field name|
|sv2ssim.FField.ctype|[dmmeta.Ctype](/txt/ssimdb/dmmeta/ctype.md)|[Pkey](/txt/exe/amc/reftypes.md#pkey)||Determined type|
|sv2ssim.FField.maxwid|i32|[Val](/txt/exe/amc/reftypes.md#val)||Max field width in chars|
|sv2ssim.FField.minval|double|[Val](/txt/exe/amc/reftypes.md#val)|1e300|Min numeric value|
|sv2ssim.FField.maxval|double|[Val](/txt/exe/amc/reftypes.md#val)|-1e300|Max numeric value|
|sv2ssim.FField.minwid_fix1|i32|[Val](/txt/exe/amc/reftypes.md#val)|100000|Min digits before .|
|sv2ssim.FField.maxwid_fix1|i32|[Val](/txt/exe/amc/reftypes.md#val)||Max digits before .|
|sv2ssim.FField.minwid_fix2|i32|[Val](/txt/exe/amc/reftypes.md#val)|100000|Min digits after .|
|sv2ssim.FField.maxwid_fix2|i32|[Val](/txt/exe/amc/reftypes.md#val)||Max digits after .|
|sv2ssim.FField.couldbe_int|bool|[Val](/txt/exe/amc/reftypes.md#val)|true||
|sv2ssim.FField.couldbe_bool|bool|[Val](/txt/exe/amc/reftypes.md#val)|true||
|sv2ssim.FField.couldbe_fixwid|bool|[Val](/txt/exe/amc/reftypes.md#val)|true|Fixed width char|
|sv2ssim.FField.couldbe_double|bool|[Val](/txt/exe/amc/reftypes.md#val)|true||
|sv2ssim.FField.rowid|i32|[Val](/txt/exe/amc/reftypes.md#val)|0||

#### Struct FField
<a href="#struct-ffield"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/sv2ssim_gen.h](/include/gen/sv2ssim_gen.h)
```
struct FField { // sv2ssim.FField
    sv2ssim::FField*    ind_field_next;     // hash next
    sv2ssim::FField*    zd_selfield_next;   // zslist link; -1 means not-in-list
    sv2ssim::FField*    zd_selfield_prev;   // previous element
    algo::cstring       name;               // Field name
    algo::Smallstr100   ctype;              // Determined type
    i32                 maxwid;             //   0  Max field width in chars
    double              minval;             //   1e300  Min numeric value
    double              maxval;             //   -1e300  Max numeric value
    i32                 minwid_fix1;        //   100000  Min digits before .
    i32                 maxwid_fix1;        //   0  Max digits before .
    i32                 minwid_fix2;        //   100000  Min digits after .
    i32                 maxwid_fix2;        //   0  Max digits after .
    bool                couldbe_int;        //   true
    bool                couldbe_bool;       //   true
    bool                couldbe_fixwid;     //   true  Fixed width char
    bool                couldbe_double;     //   true
    i32                 rowid;              //   0
    // func:sv2ssim.FField..AssignOp
    sv2ssim::FField&     operator =(const sv2ssim::FField &rhs) = delete;
    // func:sv2ssim.FField..CopyCtor
    FField(const sv2ssim::FField &rhs) = delete;
private:
    // func:sv2ssim.FField..Ctor
    inline               FField() __attribute__((nothrow));
    // func:sv2ssim.FField..Dtor
    inline               ~FField() __attribute__((nothrow));
    friend sv2ssim::FField&     field_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend sv2ssim::FField*     field_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 field_RemoveAll() __attribute__((nothrow));
    friend void                 field_RemoveLast() __attribute__((nothrow));
};
```

#### sv2ssim.FSvtype - Table for determining ctype from separated value file
<a href="#sv2ssim-fsvtype"></a>

#### sv2ssim.FSvtype Fields
<a href="#sv2ssim-fsvtype-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|sv2ssim.FSvtype.base|[dmmeta.Svtype](/txt/ssimdb/dmmeta/svtype.md)|[Base](/txt/ssimdb/dmmeta/svtype.md)|||

#### Struct FSvtype
<a href="#struct-fsvtype"></a>
*Note:* field ``sv2ssim.FSvtype.base`` has reftype ``base`` so the fields of [dmmeta.Svtype](/txt/ssimdb/dmmeta/svtype.md) above are included into the resulting struct.

Generated by [amc](/txt/exe/amc/README.md) into [include/gen/sv2ssim_gen.h](/include/gen/sv2ssim_gen.h)
```
struct FSvtype { // sv2ssim.FSvtype
    algo::Smallstr100   ctype;       // Type to choose
    i32                 maxwid;      //   0  Maximum width in chars of input field
    i32                 fixedwid1;   //   0  Max chars before decimal point
    i32                 fixedwid2;   //   0  Max chars after decimal point
    algo::Comment       comment;     //
private:
    // func:sv2ssim.FSvtype..Ctor
    inline               FSvtype() __attribute__((nothrow));
    friend sv2ssim::FSvtype&    svtype_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend sv2ssim::FSvtype*    svtype_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 svtype_RemoveAll() __attribute__((nothrow));
    friend void                 svtype_RemoveLast() __attribute__((nothrow));
};
```

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Imdb -->

### Tests
<a href="#tests"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Tests -->
The following component tests are defined for `sv2ssim`.
These can be executed with `atf_comp <comptest> -v`
|Comptest|Comment|
|---|---|
|[sv2ssim.Convert1](/test/atf_comp/sv2ssim.Convert1)||
|[sv2ssim.Convert1Signed](/test/atf_comp/sv2ssim.Convert1Signed)||
|[sv2ssim.Convert2](/test/atf_comp/sv2ssim.Convert2)||
|[sv2ssim.Convert2Tsv](/test/atf_comp/sv2ssim.Convert2Tsv)||
|[sv2ssim.UniqueFieldName](/test/atf_comp/sv2ssim.UniqueFieldName)||

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Tests -->
