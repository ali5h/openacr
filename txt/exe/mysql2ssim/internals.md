## mysql2ssim - Internals


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
for usage, see [mysql2ssim - mysql -> ssim conversion tool](/txt/exe/mysql2ssim/README.md)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Description -->

### Sources
<a href="#sources"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Sources -->
The source code license is GPL
The following source files are part of this tool:

|Source File|Comment|
|---|---|
|[cpp/gen/mysql2ssim_gen.cpp](/cpp/gen/mysql2ssim_gen.cpp)||
|[cpp/mysql2ssim.cpp](/cpp/mysql2ssim.cpp)||
|[include/gen/mysql2ssim_gen.h](/include/gen/mysql2ssim_gen.h)||
|[include/gen/mysql2ssim_gen.inl.h](/include/gen/mysql2ssim_gen.inl.h)||

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Sources -->

### Dependencies
<a href="#dependencies"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Dependencies -->
The build target depends on the following libraries
|Target|Comment|
|---|---|
|[algo_lib](/txt/lib/algo_lib/README.md)|Support library for all executables|
|[lib_mysql](/txt/lib/lib_mysql/README.md)|Mysql adaptor|

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Dependencies -->

### In Memory DB
<a href="#in-memory-db"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Imdb -->
`mysql2ssim` generated code creates the tables below.
All allocations are done through global `mysql2ssim::_db` [mysql2ssim.FDb](#mysql2ssim-fdb) structure
|Ctype|Ssimfile|Create|Access|
|---|---|---|---|
|[mysql2ssim.FDb](#mysql2ssim-fdb)||FDb._db (Global)|
|[mysql2ssim.FTobltin](#mysql2ssim-ftobltin)||

#### mysql2ssim.FDb - In-memory database for mysql2ssim
<a href="#mysql2ssim-fdb"></a>

#### mysql2ssim.FDb Fields
<a href="#mysql2ssim-fdb-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|mysql2ssim.FDb._db|[mysql2ssim.FDb](/txt/exe/mysql2ssim/internals.md#mysql2ssim-fdb)|[Global](/txt/exe/amc/reftypes.md#global)|||
|mysql2ssim.FDb.table_names|[algo.cstring](/txt/protocol/algo/cstring.md)|[Tary](/txt/exe/amc/reftypes.md#tary)||List of all tables obtained from mysql|
|mysql2ssim.FDb.in_tables|[algo.cstring](/txt/protocol/algo/cstring.md)|[Tary](/txt/exe/amc/reftypes.md#tary)|||
|mysql2ssim.FDb.cmdline|[command.mysql2ssim](/txt/protocol/command/README.md#command-mysql2ssim)|[Val](/txt/exe/amc/reftypes.md#val)|||
|mysql2ssim.FDb.tempfile|[algo_lib.FTempfile](/txt/lib/algo_lib/README.md#algo_lib-ftempfile)|[Val](/txt/exe/amc/reftypes.md#val)||Temp file where downloaded mysql goes before being handed to acr|

#### Struct FDb
<a href="#struct-fdb"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/mysql2ssim_gen.h](/include/gen/mysql2ssim_gen.h)
```
struct FDb { // mysql2ssim.FDb: In-memory database for mysql2ssim
    algo::cstring*        table_names_elems;   // pointer to elements
    u32                   table_names_n;       // number of elements in array
    u32                   table_names_max;     // max. capacity of array before realloc
    algo::cstring*        in_tables_elems;     // pointer to elements
    u32                   in_tables_n;         // number of elements in array
    u32                   in_tables_max;       // max. capacity of array before realloc
    command::mysql2ssim   cmdline;             //
    algo_lib::FTempfile   tempfile;            // Temp file where downloaded mysql goes before being handed to acr
    mysql2ssim::trace     trace;               //
};
```

#### mysql2ssim.FTobltin - 
<a href="#mysql2ssim-ftobltin"></a>

#### mysql2ssim.FTobltin Fields
<a href="#mysql2ssim-ftobltin-fields"></a>
|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|mysql2ssim.FTobltin.warn|bool|[Val](/txt/exe/amc/reftypes.md#val)||Conversion warning|
|mysql2ssim.FTobltin.err|bool|[Val](/txt/exe/amc/reftypes.md#val)||Conversion error|
|mysql2ssim.FTobltin.vals|[algo.cstring](/txt/protocol/algo/cstring.md)|[Tary](/txt/exe/amc/reftypes.md#tary)||Used during schema extraction|

#### Struct FTobltin
<a href="#struct-ftobltin"></a>
Generated by [amc](/txt/exe/amc/README.md) into [include/gen/mysql2ssim_gen.h](/include/gen/mysql2ssim_gen.h)
```
struct FTobltin { // mysql2ssim.FTobltin
    bool             warn;         //   false  Conversion warning
    bool             err;          //   false  Conversion error
    algo::cstring*   vals_elems;   // pointer to elements
    u32              vals_n;       // number of elements in array
    u32              vals_max;     // max. capacity of array before realloc
    // func:mysql2ssim.FTobltin..AssignOp
    mysql2ssim::FTobltin& operator =(const mysql2ssim::FTobltin &rhs) __attribute__((nothrow));
    // func:mysql2ssim.FTobltin..Ctor
    inline               FTobltin() __attribute__((nothrow));
    // func:mysql2ssim.FTobltin..Dtor
    inline               ~FTobltin() __attribute__((nothrow));
    // func:mysql2ssim.FTobltin..CopyCtor
    FTobltin(const mysql2ssim::FTobltin &rhs) __attribute__((nothrow));
};
```

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Imdb -->
