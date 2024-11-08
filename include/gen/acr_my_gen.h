//
// include/gen/acr_my_gen.h
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
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/command_gen.h"
#include "include/gen/dmmeta_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- acr_my_FieldIdEnum

enum acr_my_FieldIdEnum {        // acr_my.FieldId.value
     acr_my_FieldId_value   = 0
};

enum { acr_my_FieldIdEnum_N = 1 };


// --- acr_my_TableIdEnum

enum acr_my_TableIdEnum {                   // acr_my.TableId.value
     acr_my_TableId_dmmeta_Nsdb       = 0   // dmmeta.Nsdb -> acr_my.FNsdb
    ,acr_my_TableId_dmmeta_nsdb       = 0   // dmmeta.nsdb -> acr_my.FNsdb
    ,acr_my_TableId_dmmeta_Ssimfile   = 1   // dmmeta.Ssimfile -> acr_my.FSsimfile
    ,acr_my_TableId_dmmeta_ssimfile   = 1   // dmmeta.ssimfile -> acr_my.FSsimfile
};

enum { acr_my_TableIdEnum_N = 4 };

namespace acr_my { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace acr_my { // gen:ns_tclass_field
extern const char *acr_my_help;
} // gen:ns_tclass_field
// gen:ns_fwddecl2
namespace dmmeta { struct Nsdb; }
namespace dmmeta { struct Ssimfile; }
namespace acr_my { struct _db_ary_ns_curs; }
namespace acr_my { struct _db_nsdb_curs; }
namespace acr_my { struct _db_ssimfile_curs; }
namespace acr_my { struct trace; }
namespace acr_my { struct FDb; }
namespace acr_my { struct FNsdb; }
namespace acr_my { struct FSsimfile; }
namespace acr_my { struct FieldId; }
namespace acr_my { struct TableId; }
namespace acr_my { extern struct acr_my::FDb _db; }
namespace acr_my { // gen:ns_print_struct

// --- acr_my.trace
#pragma pack(push,1)
struct trace { // acr_my.trace
    // func:acr_my.trace..Ctor
    inline               trace() __attribute__((nothrow));
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:acr_my.trace.String  printfmt:Tuple
// func:acr_my.trace..Print
void                 trace_Print(acr_my::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- acr_my.FDb
// create: acr_my.FDb._db (Global)
struct FDb { // acr_my.FDb: In-memory database for acr_my
    algo_lib::Replscope   R;                   //
    algo::cstring         data_dir;            //
    algo::cstring         data_logdir;         //
    algo::cstring*        ary_ns_elems;        // pointer to elements
    u32                   ary_ns_n;            // number of elements in array
    u32                   ary_ns_max;          // max. capacity of array before realloc
    bool                  started;             //   false
    command::acr_my       cmdline;             //
    acr_my::FNsdb*        nsdb_lary[32];       // level array
    i32                   nsdb_n;              // number of elements in array
    acr_my::FSsimfile*    ssimfile_lary[32];   // level array
    i32                   ssimfile_n;          // number of elements in array
    acr_my::trace         trace;               //
};

// Reserve space (this may move memory). Insert N element at the end.
// Return aryptr to newly inserted block.
// If the RHS argument aliases the array (refers to the same memory), exit program with fatal error.
// func:acr_my.FDb.ary_ns.Addary
algo::aryptr<algo::cstring> ary_ns_Addary(algo::aryptr<algo::cstring> rhs) __attribute__((nothrow));
// Reserve space. Insert element at the end
// The new element is initialized to a default value
// func:acr_my.FDb.ary_ns.Alloc
algo::cstring&       ary_ns_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
// func:acr_my.FDb.ary_ns.AllocAt
algo::cstring&       ary_ns_AllocAt(int at) __attribute__((__warn_unused_result__, nothrow));
// Reserve space. Insert N elements at the end of the array, return pointer to array
// func:acr_my.FDb.ary_ns.AllocN
algo::aryptr<algo::cstring> ary_ns_AllocN(int n_elems) __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:acr_my.FDb.ary_ns.EmptyQ
inline bool          ary_ns_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
// func:acr_my.FDb.ary_ns.Find
inline algo::cstring* ary_ns_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return array pointer by value
// func:acr_my.FDb.ary_ns.Getary
inline algo::aryptr<algo::cstring> ary_ns_Getary() __attribute__((nothrow));
// Return pointer to last element of array, or NULL if array is empty
// func:acr_my.FDb.ary_ns.Last
inline algo::cstring* ary_ns_Last() __attribute__((nothrow, pure));
// Return max. number of items in the array
// func:acr_my.FDb.ary_ns.Max
inline i32           ary_ns_Max() __attribute__((nothrow));
// Return number of items in the array
// func:acr_my.FDb.ary_ns.N
inline i32           ary_ns_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove item by index. If index outside of range, do nothing.
// func:acr_my.FDb.ary_ns.Remove
void                 ary_ns_Remove(u32 i) __attribute__((nothrow));
// func:acr_my.FDb.ary_ns.RemoveAll
void                 ary_ns_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:acr_my.FDb.ary_ns.RemoveLast
void                 ary_ns_RemoveLast() __attribute__((nothrow));
// Make sure N *more* elements will fit in array. Process dies if out of memory
// func:acr_my.FDb.ary_ns.Reserve
inline void          ary_ns_Reserve(int n) __attribute__((nothrow));
// Make sure N elements fit in array. Process dies if out of memory
// func:acr_my.FDb.ary_ns.AbsReserve
void                 ary_ns_AbsReserve(int n) __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:acr_my.FDb.ary_ns.qFind
inline algo::cstring& ary_ns_qFind(u64 t) __attribute__((nothrow));
// Return reference to last element of array. No bounds checking
// func:acr_my.FDb.ary_ns.qLast
inline algo::cstring& ary_ns_qLast() __attribute__((nothrow));
// Return row id of specified element
// func:acr_my.FDb.ary_ns.rowid_Get
inline u64           ary_ns_rowid_Get(algo::cstring &elem) __attribute__((nothrow));
// Reserve space. Insert N elements at the end of the array, return pointer to array
// func:acr_my.FDb.ary_ns.AllocNVal
algo::aryptr<algo::cstring> ary_ns_AllocNVal(int n_elems, const algo::cstring& val) __attribute__((nothrow));
// A single element is read from input string and appended to the array.
// If the string contains an error, the array is untouched.
// Function returns success value.
// func:acr_my.FDb.ary_ns.ReadStrptrMaybe
bool                 ary_ns_ReadStrptrMaybe(algo::strptr in_str) __attribute__((nothrow));

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     acr_my.FDb.cmdline
//     algo_lib.FDb.cmdline
// func:acr_my.FDb._db.ReadArgv
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
// func:acr_my.FDb._db.MainLoop
void                 MainLoop();
// Main step
// func:acr_my.FDb._db.Step
void                 Step();
// Main function
// func:acr_my.FDb._db.Main
// this function is 'extrn' and implemented by user
void                 Main();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:acr_my.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:acr_my.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:acr_my.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:acr_my.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:acr_my.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:acr_my.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_my.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:acr_my.FDb.nsdb.Alloc
acr_my::FNsdb&       nsdb_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:acr_my.FDb.nsdb.AllocMaybe
acr_my::FNsdb*       nsdb_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:acr_my.FDb.nsdb.InsertMaybe
acr_my::FNsdb*       nsdb_InsertMaybe(const dmmeta::Nsdb &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:acr_my.FDb.nsdb.AllocMem
void*                nsdb_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:acr_my.FDb.nsdb.EmptyQ
inline bool          nsdb_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:acr_my.FDb.nsdb.Find
inline acr_my::FNsdb* nsdb_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:acr_my.FDb.nsdb.Last
inline acr_my::FNsdb* nsdb_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:acr_my.FDb.nsdb.N
inline i32           nsdb_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
// func:acr_my.FDb.nsdb.RemoveLast
void                 nsdb_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:acr_my.FDb.nsdb.qFind
inline acr_my::FNsdb& nsdb_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_my.FDb.nsdb.XrefMaybe
bool                 nsdb_XrefMaybe(acr_my::FNsdb &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:acr_my.FDb.ssimfile.Alloc
acr_my::FSsimfile&   ssimfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:acr_my.FDb.ssimfile.AllocMaybe
acr_my::FSsimfile*   ssimfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:acr_my.FDb.ssimfile.InsertMaybe
acr_my::FSsimfile*   ssimfile_InsertMaybe(const dmmeta::Ssimfile &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:acr_my.FDb.ssimfile.AllocMem
void*                ssimfile_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:acr_my.FDb.ssimfile.EmptyQ
inline bool          ssimfile_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:acr_my.FDb.ssimfile.Find
inline acr_my::FSsimfile* ssimfile_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:acr_my.FDb.ssimfile.Last
inline acr_my::FSsimfile* ssimfile_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:acr_my.FDb.ssimfile.N
inline i32           ssimfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
// func:acr_my.FDb.ssimfile.RemoveLast
void                 ssimfile_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:acr_my.FDb.ssimfile.qFind
inline acr_my::FSsimfile& ssimfile_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:acr_my.FDb.ssimfile.XrefMaybe
bool                 ssimfile_XrefMaybe(acr_my::FSsimfile &row);

// proceed to next item
// func:acr_my.FDb.ary_ns_curs.Next
inline void          _db_ary_ns_curs_Next(_db_ary_ns_curs &curs) __attribute__((nothrow));
// func:acr_my.FDb.ary_ns_curs.Reset
inline void          _db_ary_ns_curs_Reset(_db_ary_ns_curs &curs, acr_my::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_my.FDb.ary_ns_curs.ValidQ
inline bool          _db_ary_ns_curs_ValidQ(_db_ary_ns_curs &curs) __attribute__((nothrow));
// item access
// func:acr_my.FDb.ary_ns_curs.Access
inline algo::cstring& _db_ary_ns_curs_Access(_db_ary_ns_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:acr_my.FDb.nsdb_curs.Reset
inline void          _db_nsdb_curs_Reset(_db_nsdb_curs &curs, acr_my::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_my.FDb.nsdb_curs.ValidQ
inline bool          _db_nsdb_curs_ValidQ(_db_nsdb_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_my.FDb.nsdb_curs.Next
inline void          _db_nsdb_curs_Next(_db_nsdb_curs &curs) __attribute__((nothrow));
// item access
// func:acr_my.FDb.nsdb_curs.Access
inline acr_my::FNsdb& _db_nsdb_curs_Access(_db_nsdb_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:acr_my.FDb.ssimfile_curs.Reset
inline void          _db_ssimfile_curs_Reset(_db_ssimfile_curs &curs, acr_my::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:acr_my.FDb.ssimfile_curs.ValidQ
inline bool          _db_ssimfile_curs_ValidQ(_db_ssimfile_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:acr_my.FDb.ssimfile_curs.Next
inline void          _db_ssimfile_curs_Next(_db_ssimfile_curs &curs) __attribute__((nothrow));
// item access
// func:acr_my.FDb.ssimfile_curs.Access
inline acr_my::FSsimfile& _db_ssimfile_curs_Access(_db_ssimfile_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_my.FDb..Init
void                 FDb_Init();
// func:acr_my.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- acr_my.FNsdb
// create: acr_my.FDb.nsdb (Lary)
// global access: nsdb (Lary, by rowid)
struct FNsdb { // acr_my.FNsdb
    algo::Smallstr16   ns;        //
    algo::Comment      comment;   //
    bool               select;    //   false
private:
    // func:acr_my.FNsdb..Ctor
    inline               FNsdb() __attribute__((nothrow));
    friend acr_my::FNsdb&       nsdb_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_my::FNsdb*       nsdb_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 nsdb_RemoveLast() __attribute__((nothrow));
};

// Copy fields out of row
// func:acr_my.FNsdb.base.CopyOut
void                 nsdb_CopyOut(acr_my::FNsdb &row, dmmeta::Nsdb &out) __attribute__((nothrow));
// Copy fields in to row
// func:acr_my.FNsdb.base.CopyIn
void                 nsdb_CopyIn(acr_my::FNsdb &row, dmmeta::Nsdb &in) __attribute__((nothrow));

// Set all fields to initial values.
// func:acr_my.FNsdb..Init
inline void          FNsdb_Init(acr_my::FNsdb& nsdb);

// --- acr_my.FSsimfile
// create: acr_my.FDb.ssimfile (Lary)
// global access: ssimfile (Lary, by rowid)
struct FSsimfile { // acr_my.FSsimfile
    algo::Smallstr50    ssimfile;   //
    algo::Smallstr100   ctype;      //
private:
    // func:acr_my.FSsimfile..Ctor
    inline               FSsimfile() __attribute__((nothrow));
    friend acr_my::FSsimfile&   ssimfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend acr_my::FSsimfile*   ssimfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 ssimfile_RemoveLast() __attribute__((nothrow));
};

// Copy fields out of row
// func:acr_my.FSsimfile.base.CopyOut
void                 ssimfile_CopyOut(acr_my::FSsimfile &row, dmmeta::Ssimfile &out) __attribute__((nothrow));
// Copy fields in to row
// func:acr_my.FSsimfile.base.CopyIn
void                 ssimfile_CopyIn(acr_my::FSsimfile &row, dmmeta::Ssimfile &in) __attribute__((nothrow));

// func:acr_my.FSsimfile.ssimns.Get
algo::Smallstr16     ssimns_Get(acr_my::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

// func:acr_my.FSsimfile.ns.Get
algo::Smallstr16     ns_Get(acr_my::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

// func:acr_my.FSsimfile.name.Get
algo::Smallstr50     name_Get(acr_my::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));


// --- acr_my.FieldId
#pragma pack(push,1)
struct FieldId { // acr_my.FieldId: Field read helper
    i32   value;   //   -1
    // func:acr_my.FieldId.value.Cast
    inline               operator acr_my_FieldIdEnum() const __attribute__((nothrow));
    // func:acr_my.FieldId..Ctor
    inline               FieldId() __attribute__((nothrow));
    // func:acr_my.FieldId..FieldwiseCtor
    explicit inline               FieldId(i32 in_value) __attribute__((nothrow));
    // func:acr_my.FieldId..EnumCtor
    inline               FieldId(acr_my_FieldIdEnum arg) __attribute__((nothrow));
};
#pragma pack(pop)

// Get value of field as enum type
// func:acr_my.FieldId.value.GetEnum
inline acr_my_FieldIdEnum value_GetEnum(const acr_my::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:acr_my.FieldId.value.SetEnum
inline void          value_SetEnum(acr_my::FieldId& parent, acr_my_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:acr_my.FieldId.value.ToCstr
const char*          value_ToCstr(const acr_my::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:acr_my.FieldId.value.Print
void                 value_Print(const acr_my::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:acr_my.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(acr_my::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:acr_my.FieldId.value.SetStrptr
void                 value_SetStrptr(acr_my::FieldId& parent, algo::strptr rhs, acr_my_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:acr_my.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(acr_my::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of acr_my::FieldId from an ascii string.
// The format of the string is the format of the acr_my::FieldId's only field
// func:acr_my.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(acr_my::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_my.FieldId..Init
inline void          FieldId_Init(acr_my::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:acr_my.FieldId.String  printfmt:Raw
// func:acr_my.FieldId..Print
void                 FieldId_Print(acr_my::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- acr_my.TableId
struct TableId { // acr_my.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    // func:acr_my.TableId.value.Cast
    inline               operator acr_my_TableIdEnum() const __attribute__((nothrow));
    // func:acr_my.TableId..Ctor
    inline               TableId() __attribute__((nothrow));
    // func:acr_my.TableId..FieldwiseCtor
    explicit inline               TableId(i32 in_value) __attribute__((nothrow));
    // func:acr_my.TableId..EnumCtor
    inline               TableId(acr_my_TableIdEnum arg) __attribute__((nothrow));
};

// Get value of field as enum type
// func:acr_my.TableId.value.GetEnum
inline acr_my_TableIdEnum value_GetEnum(const acr_my::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:acr_my.TableId.value.SetEnum
inline void          value_SetEnum(acr_my::TableId& parent, acr_my_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:acr_my.TableId.value.ToCstr
const char*          value_ToCstr(const acr_my::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:acr_my.TableId.value.Print
void                 value_Print(const acr_my::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:acr_my.TableId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(acr_my::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:acr_my.TableId.value.SetStrptr
void                 value_SetStrptr(acr_my::TableId& parent, algo::strptr rhs, acr_my_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:acr_my.TableId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(acr_my::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of acr_my::TableId from an ascii string.
// The format of the string is the format of the acr_my::TableId's only field
// func:acr_my.TableId..ReadStrptrMaybe
bool                 TableId_ReadStrptrMaybe(acr_my::TableId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:acr_my.TableId..Init
inline void          TableId_Init(acr_my::TableId& parent);
// print string representation of ROW to string STR
// cfmt:acr_my.TableId.String  printfmt:Raw
// func:acr_my.TableId..Print
void                 TableId_Print(acr_my::TableId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace acr_my { // gen:ns_curstext

struct _db_ary_ns_curs {// cursor
    typedef algo::cstring ChildType;
    algo::cstring* elems;
    int n_elems;
    int index;
    _db_ary_ns_curs() { elems=NULL; n_elems=0; index=0; }
};


struct _db_nsdb_curs {// cursor
    typedef acr_my::FNsdb ChildType;
    acr_my::FDb *parent;
    i64 index;
    _db_nsdb_curs(){ parent=NULL; index=0; }
};


struct _db_ssimfile_curs {// cursor
    typedef acr_my::FSsimfile ChildType;
    acr_my::FDb *parent;
    i64 index;
    _db_ssimfile_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace acr_my { // gen:ns_func
// func:acr_my...StaticCheck
void                 StaticCheck();
} // gen:ns_func
// func:acr_my...main
int                  main(int argc, char **argv);
#if defined(WIN32)
// func:acr_my...WinMain
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const acr_my::trace &row);// cfmt:acr_my.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const acr_my::FieldId &row);// cfmt:acr_my.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const acr_my::TableId &row);// cfmt:acr_my.TableId.String
}
