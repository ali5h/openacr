//
// include/gen/fmdb_gen.h
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
#include "include/gen/algo_gen.h"
#include "include/gen/fm_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- fmdb_FieldIdEnum

enum fmdb_FieldIdEnum {                   // fmdb.FieldId.value
     fmdb_FieldId_alarm             = 0
    ,fmdb_FieldId_code              = 1
    ,fmdb_FieldId_object            = 2
    ,fmdb_FieldId_objtype           = 3
    ,fmdb_FieldId_objinst           = 4
    ,fmdb_FieldId_objprefix         = 5
    ,fmdb_FieldId_flag              = 6
    ,fmdb_FieldId_severity          = 7
    ,fmdb_FieldId_n_occurred        = 8
    ,fmdb_FieldId_first_time        = 9
    ,fmdb_FieldId_last_time         = 10
    ,fmdb_FieldId_clear_time        = 11
    ,fmdb_FieldId_update_time       = 12
    ,fmdb_FieldId_objtype_summary   = 13
    ,fmdb_FieldId_summary           = 14
    ,fmdb_FieldId_description       = 15
    ,fmdb_FieldId_source            = 16
    ,fmdb_FieldId_alm_code          = 17
    ,fmdb_FieldId_alm_objtype       = 18
    ,fmdb_FieldId_alm_source        = 19
    ,fmdb_FieldId_comment           = 20
    ,fmdb_FieldId_value             = 21
};

enum { fmdb_FieldIdEnum_N = 22 };

namespace fmdb { // gen:ns_pkeytypedef
    typedef algo::Smallstr200 AlarmPkey;
    typedef fm::Code AlmCodePkey;
    typedef fm::Objtype AlmObjtypePkey;
    typedef fm::Source AlmSourcePkey;
} // gen:ns_pkeytypedef
namespace fmdb { // gen:ns_tclass_field
} // gen:ns_tclass_field
// gen:ns_fwddecl2
namespace fmdb { struct Alarm; }
namespace fmdb { struct AlmCode; }
namespace fmdb { struct AlmObjtype; }
namespace fmdb { struct AlmSource; }
namespace fmdb { struct FieldId; }
namespace fmdb { // gen:ns_print_struct

// --- fmdb.Alarm
struct Alarm { // fmdb.Alarm
    algo::Smallstr200   alarm;             // Alarm identity: code@object
    fm::Flag            flag;              // Flag: raised or cleared
    fm::Severity        severity;          // Perceived severity
    i32                 n_occurred;        //   0  How many times the alarm occurred since first_time
    algo::UnTime        first_time;        // Time of first occurrence
    algo::UnTime        last_time;         // Time of last occurrence
    algo::UnTime        clear_time;        // Time when the alarm has beed cleared (only for cleared alarms
    algo::UnTime        update_time;       // Time of last update
    fm::Summary         objtype_summary;   // Object type explained
    fm::Summary         summary;           // Alarm summary from inventory
    fm::Description     description;       // Alarm message from object
    fm::Source          source;            // Subsystem where alarm has been detected
    // func:fmdb.Alarm..Ctor
    inline               Alarm() __attribute__((nothrow));
};

// func:fmdb.Alarm.code.Get
fm::Code             code_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
// func:fmdb.Alarm.code.Get2
fm::Code             Alarm_code_Get(algo::strptr arg) __attribute__((nothrow));

// func:fmdb.Alarm.object.Get
algo::Smallstr200    object_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
// func:fmdb.Alarm.object.Get2
algo::Smallstr200    Alarm_object_Get(algo::strptr arg) __attribute__((nothrow));

// func:fmdb.Alarm.objtype.Get
fm::Objtype          objtype_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
// func:fmdb.Alarm.objtype.Get2
fm::Objtype          Alarm_objtype_Get(algo::strptr arg) __attribute__((nothrow));

// func:fmdb.Alarm.objinst.Get
fm::Objinst          objinst_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
// func:fmdb.Alarm.objinst.Get2
fm::Objinst          Alarm_objinst_Get(algo::strptr arg) __attribute__((nothrow));

// func:fmdb.Alarm.objprefix.Get
algo::Smallstr50     objprefix_Get(fmdb::Alarm& parent) __attribute__((__warn_unused_result__, nothrow));
// func:fmdb.Alarm.objprefix.Get2
algo::Smallstr50     Alarm_objprefix_Get(algo::strptr arg) __attribute__((nothrow));

// func:fmdb.Alarm..Concat_code_object
tempstr              Alarm_Concat_code_object( const algo::strptr& code ,const algo::strptr& object );
// func:fmdb.Alarm..Concat_objtype_objinst
tempstr              Alarm_Concat_objtype_objinst( const algo::strptr& objtype ,const algo::strptr& objinst );
// func:fmdb.Alarm..ReadFieldMaybe
bool                 Alarm_ReadFieldMaybe(fmdb::Alarm& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::Alarm from an ascii string.
// The format of the string is an ssim Tuple
// func:fmdb.Alarm..ReadStrptrMaybe
bool                 Alarm_ReadStrptrMaybe(fmdb::Alarm &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:fmdb.Alarm..Init
void                 Alarm_Init(fmdb::Alarm& parent);
// print string representation of ROW to string STR
// cfmt:fmdb.Alarm.String  printfmt:Tuple
// func:fmdb.Alarm..Print
void                 Alarm_Print(fmdb::Alarm& row, algo::cstring& str) __attribute__((nothrow));

// --- fmdb.AlmCode
struct AlmCode { // fmdb.AlmCode
    fm::Code       alm_code;   // Alarm code
    fm::Severity   severity;   // Assigned severity
    fm::Source     source;     //
    fm::Summary    summary;    // Alarm summary (slogan)
    // func:fmdb.AlmCode..Ctor
    inline               AlmCode() __attribute__((nothrow));
};

// func:fmdb.AlmCode..ReadFieldMaybe
bool                 AlmCode_ReadFieldMaybe(fmdb::AlmCode& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::AlmCode from an ascii string.
// The format of the string is an ssim Tuple
// func:fmdb.AlmCode..ReadStrptrMaybe
bool                 AlmCode_ReadStrptrMaybe(fmdb::AlmCode &parent, algo::strptr in_str) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fmdb.AlmCode.String  printfmt:Tuple
// func:fmdb.AlmCode..Print
void                 AlmCode_Print(fmdb::AlmCode& row, algo::cstring& str) __attribute__((nothrow));

// --- fmdb.AlmObjtype
struct AlmObjtype { // fmdb.AlmObjtype: Alarm resource type
    fm::Objtype   alm_objtype;   // Object type
    fm::Summary   summary;       // Object type summary
    // func:fmdb.AlmObjtype..Ctor
    inline               AlmObjtype() __attribute__((nothrow));
};

// func:fmdb.AlmObjtype..ReadFieldMaybe
bool                 AlmObjtype_ReadFieldMaybe(fmdb::AlmObjtype& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::AlmObjtype from an ascii string.
// The format of the string is an ssim Tuple
// func:fmdb.AlmObjtype..ReadStrptrMaybe
bool                 AlmObjtype_ReadStrptrMaybe(fmdb::AlmObjtype &parent, algo::strptr in_str) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fmdb.AlmObjtype.String  printfmt:Tuple
// func:fmdb.AlmObjtype..Print
void                 AlmObjtype_Print(fmdb::AlmObjtype& row, algo::cstring& str) __attribute__((nothrow));

// --- fmdb.AlmSource
struct AlmSource { // fmdb.AlmSource: Subsystem where alarm has been detected
    fm::Source      alm_source;   //
    algo::Comment   comment;      //
    // func:fmdb.AlmSource..Ctor
    inline               AlmSource() __attribute__((nothrow));
};

// func:fmdb.AlmSource..ReadFieldMaybe
bool                 AlmSource_ReadFieldMaybe(fmdb::AlmSource& parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of fmdb::AlmSource from an ascii string.
// The format of the string is an ssim Tuple
// func:fmdb.AlmSource..ReadStrptrMaybe
bool                 AlmSource_ReadStrptrMaybe(fmdb::AlmSource &parent, algo::strptr in_str) __attribute__((nothrow));
// print string representation of ROW to string STR
// cfmt:fmdb.AlmSource.String  printfmt:Tuple
// func:fmdb.AlmSource..Print
void                 AlmSource_Print(fmdb::AlmSource& row, algo::cstring& str) __attribute__((nothrow));

// --- fmdb.FieldId
#pragma pack(push,1)
struct FieldId { // fmdb.FieldId: Field read helper
    i32   value;   //   -1
    // func:fmdb.FieldId.value.Cast
    inline               operator fmdb_FieldIdEnum() const __attribute__((nothrow));
    // func:fmdb.FieldId..Ctor
    inline               FieldId() __attribute__((nothrow));
    // func:fmdb.FieldId..FieldwiseCtor
    explicit inline               FieldId(i32 in_value) __attribute__((nothrow));
    // func:fmdb.FieldId..EnumCtor
    inline               FieldId(fmdb_FieldIdEnum arg) __attribute__((nothrow));
};
#pragma pack(pop)

// Get value of field as enum type
// func:fmdb.FieldId.value.GetEnum
inline fmdb_FieldIdEnum value_GetEnum(const fmdb::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
// func:fmdb.FieldId.value.SetEnum
inline void          value_SetEnum(fmdb::FieldId& parent, fmdb_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
// func:fmdb.FieldId.value.ToCstr
const char*          value_ToCstr(const fmdb::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
// func:fmdb.FieldId.value.Print
void                 value_Print(const fmdb::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
// func:fmdb.FieldId.value.SetStrptrMaybe
bool                 value_SetStrptrMaybe(fmdb::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
// func:fmdb.FieldId.value.SetStrptr
void                 value_SetStrptr(fmdb::FieldId& parent, algo::strptr rhs, fmdb_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
// func:fmdb.FieldId.value.ReadStrptrMaybe
bool                 value_ReadStrptrMaybe(fmdb::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of fmdb::FieldId from an ascii string.
// The format of the string is the format of the fmdb::FieldId's only field
// func:fmdb.FieldId..ReadStrptrMaybe
bool                 FieldId_ReadStrptrMaybe(fmdb::FieldId &parent, algo::strptr in_str) __attribute__((nothrow));
// Set all fields to initial values.
// func:fmdb.FieldId..Init
inline void          FieldId_Init(fmdb::FieldId& parent);
// print string representation of ROW to string STR
// cfmt:fmdb.FieldId.String  printfmt:Raw
// func:fmdb.FieldId..Print
void                 FieldId_Print(fmdb::FieldId& row, algo::cstring& str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace fmdb { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::Alarm &row);// cfmt:fmdb.Alarm.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::AlmCode &row);// cfmt:fmdb.AlmCode.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::AlmObjtype &row);// cfmt:fmdb.AlmObjtype.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::AlmSource &row);// cfmt:fmdb.AlmSource.String
inline algo::cstring &operator <<(algo::cstring &str, const fmdb::FieldId &row);// cfmt:fmdb.FieldId.String
}
