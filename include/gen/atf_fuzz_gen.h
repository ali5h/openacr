//
// include/gen/atf_fuzz_gen.h
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
#include "include/gen/command_gen.h"
#include "include/gen/atfdb_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/dev_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- atf_fuzz_FieldIdEnum

enum atf_fuzz_FieldIdEnum {        // atf_fuzz.FieldId.value
     atf_fuzz_FieldId_value   = 0
};

enum { atf_fuzz_FieldIdEnum_N = 1 };


// --- atf_fuzz_TableIdEnum

enum atf_fuzz_TableIdEnum {              // atf_fuzz.TableId.value
     atf_fuzz_TableId_dev_Target   = 0   // dev.Target -> atf_fuzz.FTarget
    ,atf_fuzz_TableId_dev_target   = 0   // dev.target -> atf_fuzz.FTarget
};

enum { atf_fuzz_TableIdEnum_N = 2 };

namespace atf_fuzz { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace atf_fuzz { // gen:ns_tclass_field
extern const char *atf_fuzz_help;
} // gen:ns_tclass_field
// gen:ns_fwddecl2
namespace atfdb { struct Fuzzstrat; }
namespace dev { struct Target; }
namespace atf_fuzz { struct _db_fuzzstrat_curs; }
namespace atf_fuzz { struct _db_target_curs; }
namespace atf_fuzz { struct trace; }
namespace atf_fuzz { struct FDb; }
namespace atf_fuzz { struct FFuzzstrat; }
namespace atf_fuzz { struct FTarget; }
namespace atf_fuzz { struct FieldId; }
namespace atf_fuzz { struct TableId; }
namespace atf_fuzz { extern struct atf_fuzz::FDb _db; }
namespace atf_fuzz { // hook_fcn_typedef
    typedef void (*fuzzstrat_step_hook)(); // hook:atf_fuzz.FFuzzstrat.step
} // hook_decl
namespace atf_fuzz { // gen:ns_print_struct

// --- atf_fuzz.trace
#pragma pack(push,1)
struct trace { // atf_fuzz.trace
    // func:atf_fuzz.trace..Ctor
    inline               trace() __attribute__((nothrow));
};
#pragma pack(pop)

// print string representation of ROW to string STR
// cfmt:atf_fuzz.trace.String  printfmt:Tuple
// func:atf_fuzz.trace..Print
void                 trace_Print(atf_fuzz::trace& row, algo::cstring& str) __attribute__((nothrow));

// --- atf_fuzz.FDb
// create: atf_fuzz.FDb._db (Global)
struct FDb { // atf_fuzz.FDb: In-memory database for atf_fuzz
    command::atf_fuzz       cmdline;                    //
    atf_fuzz::FFuzzstrat*   fuzzstrat_lary[32];         // level array
    i32                     fuzzstrat_n;                // number of elements in array
    atf_fuzz::FTarget*      target_lary[32];            // level array
    i32                     target_n;                   // number of elements in array
    atf_fuzz::FTarget**     ind_target_buckets_elems;   // pointer to bucket array
    i32                     ind_target_buckets_n;       // number of elements in bucket array
    i32                     ind_target_n;               // number of elements in the hash table
    atf_fuzz::FTarget*      c_target;                   // optional pointer
    atf_fuzz::trace         trace;                      //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     atf_fuzz.FDb.cmdline
//     algo_lib.FDb.cmdline
// func:atf_fuzz.FDb._db.ReadArgv
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
// func:atf_fuzz.FDb._db.MainLoop
void                 MainLoop();
// Main step
// func:atf_fuzz.FDb._db.Step
void                 Step();
// Main function
// func:atf_fuzz.FDb._db.Main
// this function is 'extrn' and implemented by user
void                 Main();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
// func:atf_fuzz.FDb._db.InsertStrptrMaybe
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
// func:atf_fuzz.FDb._db.LoadTuplesMaybe
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
// func:atf_fuzz.FDb._db.LoadTuplesFile
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
// func:atf_fuzz.FDb._db.LoadTuplesFd
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
// func:atf_fuzz.FDb._db.LoadSsimfileMaybe
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
// func:atf_fuzz.FDb._db.Steps
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:atf_fuzz.FDb._db.XrefMaybe
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:atf_fuzz.FDb.fuzzstrat.Alloc
atf_fuzz::FFuzzstrat& fuzzstrat_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:atf_fuzz.FDb.fuzzstrat.AllocMaybe
atf_fuzz::FFuzzstrat* fuzzstrat_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:atf_fuzz.FDb.fuzzstrat.InsertMaybe
atf_fuzz::FFuzzstrat* fuzzstrat_InsertMaybe(const atfdb::Fuzzstrat &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:atf_fuzz.FDb.fuzzstrat.AllocMem
void*                fuzzstrat_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:atf_fuzz.FDb.fuzzstrat.EmptyQ
inline bool          fuzzstrat_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:atf_fuzz.FDb.fuzzstrat.Find
inline atf_fuzz::FFuzzstrat* fuzzstrat_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:atf_fuzz.FDb.fuzzstrat.Last
inline atf_fuzz::FFuzzstrat* fuzzstrat_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:atf_fuzz.FDb.fuzzstrat.N
inline i32           fuzzstrat_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:atf_fuzz.FDb.fuzzstrat.RemoveAll
void                 fuzzstrat_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:atf_fuzz.FDb.fuzzstrat.RemoveLast
void                 fuzzstrat_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:atf_fuzz.FDb.fuzzstrat.qFind
inline atf_fuzz::FFuzzstrat& fuzzstrat_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:atf_fuzz.FDb.fuzzstrat.XrefMaybe
bool                 fuzzstrat_XrefMaybe(atf_fuzz::FFuzzstrat &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
// func:atf_fuzz.FDb.target.Alloc
atf_fuzz::FTarget&   target_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
// func:atf_fuzz.FDb.target.AllocMaybe
atf_fuzz::FTarget*   target_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
// func:atf_fuzz.FDb.target.InsertMaybe
atf_fuzz::FTarget*   target_InsertMaybe(const dev::Target &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
// func:atf_fuzz.FDb.target.AllocMem
void*                target_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
// func:atf_fuzz.FDb.target.EmptyQ
inline bool          target_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
// func:atf_fuzz.FDb.target.Find
inline atf_fuzz::FTarget* target_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
// func:atf_fuzz.FDb.target.Last
inline atf_fuzz::FTarget* target_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
// func:atf_fuzz.FDb.target.N
inline i32           target_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
// func:atf_fuzz.FDb.target.RemoveAll
void                 target_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
// func:atf_fuzz.FDb.target.RemoveLast
void                 target_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
// func:atf_fuzz.FDb.target.qFind
inline atf_fuzz::FTarget& target_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
// func:atf_fuzz.FDb.target.XrefMaybe
bool                 target_XrefMaybe(atf_fuzz::FTarget &row);

// Return true if hash is empty
// func:atf_fuzz.FDb.ind_target.EmptyQ
inline bool          ind_target_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
// func:atf_fuzz.FDb.ind_target.Find
atf_fuzz::FTarget*   ind_target_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
// func:atf_fuzz.FDb.ind_target.FindX
atf_fuzz::FTarget&   ind_target_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
// func:atf_fuzz.FDb.ind_target.GetOrCreate
atf_fuzz::FTarget&   ind_target_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
// func:atf_fuzz.FDb.ind_target.N
inline i32           ind_target_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
// func:atf_fuzz.FDb.ind_target.InsertMaybe
bool                 ind_target_InsertMaybe(atf_fuzz::FTarget& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
// func:atf_fuzz.FDb.ind_target.Remove
void                 ind_target_Remove(atf_fuzz::FTarget& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
// func:atf_fuzz.FDb.ind_target.Reserve
void                 ind_target_Reserve(int n) __attribute__((nothrow));

// cursor points to valid item
// func:atf_fuzz.FDb.fuzzstrat_curs.Reset
inline void          _db_fuzzstrat_curs_Reset(_db_fuzzstrat_curs &curs, atf_fuzz::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:atf_fuzz.FDb.fuzzstrat_curs.ValidQ
inline bool          _db_fuzzstrat_curs_ValidQ(_db_fuzzstrat_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:atf_fuzz.FDb.fuzzstrat_curs.Next
inline void          _db_fuzzstrat_curs_Next(_db_fuzzstrat_curs &curs) __attribute__((nothrow));
// item access
// func:atf_fuzz.FDb.fuzzstrat_curs.Access
inline atf_fuzz::FFuzzstrat& _db_fuzzstrat_curs_Access(_db_fuzzstrat_curs &curs) __attribute__((nothrow));
// cursor points to valid item
// func:atf_fuzz.FDb.target_curs.Reset
inline void          _db_target_curs_Reset(_db_target_curs &curs, atf_fuzz::FDb &parent) __attribute__((nothrow));
// cursor points to valid item
// func:atf_fuzz.FDb.target_curs.ValidQ
inline bool          _db_target_curs_ValidQ(_db_target_curs &curs) __attribute__((nothrow));
// proceed to next item
// func:atf_fuzz.FDb.target_curs.Next
inline void          _db_target_curs_Next(_db_target_curs &curs) __attribute__((nothrow));
// item access
// func:atf_fuzz.FDb.target_curs.Access
inline atf_fuzz::FTarget& _db_target_curs_Access(_db_target_curs &curs) __attribute__((nothrow));
// Set all fields to initial values.
// func:atf_fuzz.FDb..Init
void                 FDb_Init();
// func:atf_fuzz.FDb..Uninit
void                 FDb_Uninit() __attribute__((nothrow));

// --- atf_fuzz.FFuzzstrat
// create: atf_fuzz.FDb.fuzzstrat (Lary)
// global access: fuzzstrat (Lary, by rowid)
struct FFuzzstrat { // atf_fuzz.FFuzzstrat
    algo::Smallstr50                fuzzstrat;   //
    algo::Comment                   comment;     //
    atf_fuzz::fuzzstrat_step_hook   step;        //   NULL  Pointer to a function
private:
    // func:atf_fuzz.FFuzzstrat..Ctor
    inline               FFuzzstrat() __attribute__((nothrow));
    friend atf_fuzz::FFuzzstrat& fuzzstrat_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_fuzz::FFuzzstrat* fuzzstrat_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 fuzzstrat_RemoveAll() __attribute__((nothrow));
    friend void                 fuzzstrat_RemoveLast() __attribute__((nothrow));
};

// Copy fields out of row
// func:atf_fuzz.FFuzzstrat.base.CopyOut
void                 fuzzstrat_CopyOut(atf_fuzz::FFuzzstrat &row, atfdb::Fuzzstrat &out) __attribute__((nothrow));
// Copy fields in to row
// func:atf_fuzz.FFuzzstrat.base.CopyIn
void                 fuzzstrat_CopyIn(atf_fuzz::FFuzzstrat &row, atfdb::Fuzzstrat &in) __attribute__((nothrow));

// Invoke function by pointer
// func:atf_fuzz.FFuzzstrat.step.Call
inline void          step_Call(atf_fuzz::FFuzzstrat& fuzzstrat) __attribute__((nothrow));

// Set all fields to initial values.
// func:atf_fuzz.FFuzzstrat..Init
inline void          FFuzzstrat_Init(atf_fuzz::FFuzzstrat& fuzzstrat);

// --- atf_fuzz.FTarget
// create: atf_fuzz.FDb.target (Lary)
// global access: target (Lary, by rowid)
// global access: ind_target (Thash, hash field target)
// global access: c_target (Ptr)
struct FTarget { // atf_fuzz.FTarget
    atf_fuzz::FTarget*   ind_target_next;   // hash next
    algo::Smallstr16     target;            // Primary key - name of target
    // func:atf_fuzz.FTarget..AssignOp
    inline atf_fuzz::FTarget& operator =(const atf_fuzz::FTarget &rhs) = delete;
    // func:atf_fuzz.FTarget..CopyCtor
    inline               FTarget(const atf_fuzz::FTarget &rhs) = delete;
private:
    // func:atf_fuzz.FTarget..Ctor
    inline               FTarget() __attribute__((nothrow));
    // func:atf_fuzz.FTarget..Dtor
    inline               ~FTarget() __attribute__((nothrow));
    friend atf_fuzz::FTarget&   target_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_fuzz::FTarget*   target_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 target_RemoveAll() __attribute__((nothrow));
    friend void                 target_RemoveLast() __attribute__((nothrow));
};

// Copy fields out of row
// func:atf_fuzz.FTarget.base.CopyOut
void                 target_CopyOut(atf_fuzz::FTarget &row, dev::Target &out) __attribute__((nothrow));
// Copy fields in to row
// func:atf_fuzz.FTarget.base.CopyIn
void                 target_CopyIn(atf_fuzz::FTarget &row, dev::Target &in) __attribute__((nothrow));

// Set all fields to initial values.
// func:atf_fuzz.FTarget..Init
inline void          FTarget_Init(atf_fuzz::FTarget& target);
// func:atf_fuzz.FTarget..Uninit
void                 FTarget_Uninit(atf_fuzz::FTarget& target) __attribute__((nothrow));

// --- atf_fuzz.FieldId
#pragma pack(push,1)
struct FieldId { // atf_fuzz.FieldId: Field read helper
    i32   value;   //   -1
    // func:atf_fuzz.FieldId.value.Cast
    inline               operator atf_fuzz_FieldIdEnum() const __attribute__((nothrow));
    // func:atf_fuzz.FieldId..Ctor
    inline               FieldId() __attribute__((nothrow));
    // func:atf_fuzz.FieldId..FieldwiseCtor
    explicit inline               FieldId(i32 in_value) __attribute__((nothrow));
    // func:atf_fuzz.FieldId..EnumCtor
    inline               FieldId(atf_fuzz_FieldIdEnum arg) __attribute__((nothrow));
};
#pragma pack(pop)

// Get value of field as enum type
// func:atf_fuzz.FieldId.value.GetEnum
inline atf_fuzz_FieldIdEnum value_GetEnum(const atf_fuzz::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:atf_fuzz.FieldId.value.SetEnum
inline void          value_SetEnum(atf_fuzz::FieldId& parent, atf_fuzz_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:atf_fuzz.FieldId.value.ToCstr
const char*          value_ToCstr(const atf_fuzz::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:atf_fuzz.FieldId.value.Print
void                 value_Print(const atf_fuzz::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:atf_fuzz.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(atf_fuzz::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:atf_fuzz.FieldId.value.SetStrptr
void                 value_SetStrptr(atf_fuzz::FieldId& parent, algo::strptr rhs, atf_fuzz_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:atf_fuzz.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(atf_fuzz::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of atf_fuzz::FieldId from an ascii string.
// The format of the string is the format of the atf_fuzz::FieldId's only field
// func:atf_fuzz.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(atf_fuzz::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:atf_fuzz.FieldId..Init
inline void          FieldId_Init(atf_fuzz::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:atf_fuzz.FieldId.String  printfmt:Raw
// func:atf_fuzz.FieldId..Print
void                 FieldId_Print(atf_fuzz::FieldId& row, algo::cstring& str) __attribute__((nothrow));

// --- atf_fuzz.TableId
struct TableId { // atf_fuzz.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    // func:atf_fuzz.TableId.value.Cast
    inline               operator atf_fuzz_TableIdEnum() const __attribute__((nothrow));
    // func:atf_fuzz.TableId..Ctor
    inline               TableId() __attribute__((nothrow));
    // func:atf_fuzz.TableId..FieldwiseCtor
    explicit inline               TableId(i32 in_value) __attribute__((nothrow));
    // func:atf_fuzz.TableId..EnumCtor
    inline               TableId(atf_fuzz_TableIdEnum arg) __attribute__((nothrow));
};

// Get value of field as enum type
// func:atf_fuzz.TableId.value.GetEnum
inline atf_fuzz_TableIdEnum value_GetEnum(const atf_fuzz::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:atf_fuzz.TableId.value.SetEnum
inline void          value_SetEnum(atf_fuzz::TableId& parent, atf_fuzz_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:atf_fuzz.TableId.value.ToCstr
const char*          value_ToCstr(const atf_fuzz::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:atf_fuzz.TableId.value.Print
void                 value_Print(const atf_fuzz::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:atf_fuzz.TableId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(atf_fuzz::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:atf_fuzz.TableId.value.SetStrptr
void                 value_SetStrptr(atf_fuzz::TableId& parent, algo::strptr rhs, atf_fuzz_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:atf_fuzz.TableId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(atf_fuzz::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of atf_fuzz::TableId from an ascii string.
// The format of the string is the format of the atf_fuzz::TableId's only field
// func:atf_fuzz.TableId..ReadStrptrMaybe
bool                 TableId_ReadStrptrMaybe(atf_fuzz::TableId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:atf_fuzz.TableId..Init
inline void          TableId_Init(atf_fuzz::TableId& parent);
// print string representation of ROW to string STR
// cfmt:atf_fuzz.TableId.String  printfmt:Raw
// func:atf_fuzz.TableId..Print
void                 TableId_Print(atf_fuzz::TableId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace atf_fuzz { // gen:ns_curstext

struct _db_fuzzstrat_curs {// cursor
    typedef atf_fuzz::FFuzzstrat ChildType;
    atf_fuzz::FDb *parent;
    i64 index;
    _db_fuzzstrat_curs(){ parent=NULL; index=0; }
};


struct _db_target_curs {// cursor
    typedef atf_fuzz::FTarget ChildType;
    atf_fuzz::FDb *parent;
    i64 index;
    _db_target_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace atf_fuzz { // gen:ns_func
// User-implemented function from gstatic:atf_fuzz.FDb.fuzzstrat
// func:atf_fuzz...fuzzstrat_skip_inputs
// this function is 'extrn' and implemented by user
void                 fuzzstrat_skip_inputs();
// func:atf_fuzz...StaticCheck
void                 StaticCheck();
} // gen:ns_func
// func:atf_fuzz...main
int                  main(int argc, char **argv);
#if defined(WIN32)
// func:atf_fuzz...WinMain
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const atf_fuzz::trace &row);// cfmt:atf_fuzz.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const atf_fuzz::FieldId &row);// cfmt:atf_fuzz.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const atf_fuzz::TableId &row);// cfmt:atf_fuzz.TableId.String
}
