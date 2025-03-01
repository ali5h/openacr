//
// include/gen/lib_mysql_gen.h
// Generated by AMC
//
// Copyright (C) 2008-2013 AlgoEngineering LLC
// Copyright (C) 2013-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2020-2023 Astra
// Copyright (C) 2023 AlgoRND
//
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


#pragma once
#include <mariadb/mysql.h>
//#pragma endinclude
// gen:ns_enums

// --- lib_mysql_FieldIdEnum

enum lib_mysql_FieldIdEnum {        // lib_mysql.FieldId.value
     lib_mysql_FieldId_value   = 0
};

enum { lib_mysql_FieldIdEnum_N = 1 };

namespace lib_mysql { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace lib_mysql { // gen:ns_tclass_field
} // gen:ns_tclass_field
// gen:ns_fwddecl2
namespace lib_mysql { struct trace; }
namespace lib_mysql { struct FDb; }
namespace lib_mysql { struct FieldId; }
namespace lib_mysql { struct Res; }
namespace lib_mysql { extern struct lib_mysql::FDb _db; }
namespace lib_mysql { // gen:ns_print_struct

// --- lib_mysql.trace
#pragma pack(push,1)
struct trace { // lib_mysql.trace
    // func:lib_mysql.trace..Ctor
    inline               trace() __attribute__((nothrow));
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:lib_mysql.trace.String  printfmt:Tuple
// func:lib_mysql.trace..Print
void                 trace_Print(lib_mysql::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- lib_mysql.FDb
// create: lib_mysql.FDb._db (Global)
struct FDb { // lib_mysql.FDb: In-memory database for lib_mysql
    MYSQL*             mysql;   // optional pointer
    lib_mysql::trace   trace;   //
};

// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:lib_mysql.FDb.res.XrefMaybe
bool                 res_XrefMaybe(lib_mysql::Res &row);

// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:lib_mysql.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:lib_mysql.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:lib_mysql.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:lib_mysql.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:lib_mysql.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:lib_mysql.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:lib_mysql.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Declaration for user-defined cleanup function
// User-defined cleanup function invoked for field mysql of lib_mysql::FDb
// func:lib_mysql.FDb.mysql.Cleanup
// this function is 'extrn' and implemented by user
void                 mysql_Cleanup() __attribute__((nothrow));

// Set all fields to initial values.
// func:lib_mysql.FDb..Init
void                 FDb_Init();
// func:lib_mysql.FDb..Uninit
inline void          FDb_Uninit() __attribute__((nothrow));

// --- lib_mysql.FieldId
#pragma pack(push,1)
struct FieldId { // lib_mysql.FieldId: Field read helper
    i32   value;   //   -1
    // func:lib_mysql.FieldId.value.Cast
    inline               operator lib_mysql_FieldIdEnum() const __attribute__((nothrow));
    // func:lib_mysql.FieldId..Ctor
    inline               FieldId() __attribute__((nothrow));
    // func:lib_mysql.FieldId..FieldwiseCtor
    explicit inline               FieldId(i32 in_value) __attribute__((nothrow));
    // func:lib_mysql.FieldId..EnumCtor
    inline               FieldId(lib_mysql_FieldIdEnum arg) __attribute__((nothrow));
};
#pragma pack(pop)

// Get value of field as enum type
// func:lib_mysql.FieldId.value.GetEnum
inline lib_mysql_FieldIdEnum value_GetEnum(const lib_mysql::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:lib_mysql.FieldId.value.SetEnum
inline void          value_SetEnum(lib_mysql::FieldId& parent, lib_mysql_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:lib_mysql.FieldId.value.ToCstr
const char*          value_ToCstr(const lib_mysql::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:lib_mysql.FieldId.value.Print
void                 value_Print(const lib_mysql::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:lib_mysql.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(lib_mysql::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:lib_mysql.FieldId.value.SetStrptr
void                 value_SetStrptr(lib_mysql::FieldId& parent, algo::strptr rhs, lib_mysql_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:lib_mysql.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(lib_mysql::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_mysql::FieldId from an ascii string.
// The format of the string is the format of the lib_mysql::FieldId's only field
// func:lib_mysql.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(lib_mysql::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:lib_mysql.FieldId..Init
inline void          FieldId_Init(lib_mysql::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:lib_mysql.FieldId.String  printfmt:Raw
// func:lib_mysql.FieldId..Print
void                 FieldId_Print(lib_mysql::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- lib_mysql.Res
// create: lib_mysql.FDb.res (Cppstack)
struct Res { // lib_mysql.Res
    MYSQL_RES*   res;   // optional pointer
    // func:lib_mysql.Res..Ctor
    inline               Res() __attribute__((nothrow));
    // func:lib_mysql.Res..Dtor
    inline               ~Res() __attribute__((nothrow));
};

// Declaration for user-defined cleanup function
// User-defined cleanup function invoked for field res of lib_mysql::Res
// func:lib_mysql.Res.res.Cleanup
// this function is 'extrn' and implemented by user
void                 res_Cleanup(lib_mysql::Res& res) __attribute__((nothrow));

// Set all fields to initial values.
// func:lib_mysql.Res..Init
inline void          Res_Init(lib_mysql::Res& res);
// func:lib_mysql.Res..Uninit
inline void          Res_Uninit(lib_mysql::Res& res) __attribute__((nothrow));
} // gen:ns_print_struct
namespace lib_mysql { // gen:ns_func
// func:lib_mysql...StaticCheck
void                 StaticCheck();
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const lib_mysql::trace &row);// cfmt:lib_mysql.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_mysql::FieldId &row);// cfmt:lib_mysql.FieldId.String
}
