//
// include/gen/lib_json_gen.inl.h
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
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude

// --- lib_json.trace..Init
// Set all fields to initial values.
inline void lib_json::trace_Init(lib_json::trace& parent) {
    parent.alloc__db_node = u64(0);
    parent.del__db_node = u64(0);
}

// --- lib_json.trace..Ctor
inline  lib_json::trace::trace() {
    lib_json::trace_Init(*this);
}

// --- lib_json.FDb.ind_objfld.EmptyQ
// Return true if hash is empty
inline bool lib_json::ind_objfld_EmptyQ() {
    return _db.ind_objfld_n == 0;
}

// --- lib_json.FDb.ind_objfld.N
// Return number of items in the hash
inline i32 lib_json::ind_objfld_N() {
    return _db.ind_objfld_n;
}

// --- lib_json.FDb.JsonNumChar.Match
inline bool lib_json::JsonNumCharQ(u32 ch) {
    bool ret = false;
    ret |= ch == '+';
    ret |= (ch - u32('-')) < u32(2);
    ret |= (ch - u32('0')) < u32(10);
    ret |= ch == 'E';
    ret |= ch == 'e';
    return ret;
}

// --- lib_json.FDb.JsonFirstNumChar.Match
inline bool lib_json::JsonFirstNumCharQ(u32 ch) {
    bool ret = false;
    ret |= ch == '-';
    ret |= (ch - u32('0')) < u32(10);
    return ret;
}

// --- lib_json.FldKey..Hash
inline u32 lib_json::FldKey_Hash(u32 prev, const lib_json::FldKey& rhs) {
    prev = u64_Hash(prev, u64(rhs.object));
    prev = strptr_Hash(prev, rhs.field);
    return prev;
}

// --- lib_json.FldKey..EqOp
inline bool lib_json::FldKey::operator ==(const lib_json::FldKey &rhs) const {
    return lib_json::FldKey_Eq(const_cast<lib_json::FldKey&>(*this),const_cast<lib_json::FldKey&>(rhs));
}

// --- lib_json.FldKey..NeOp
inline bool lib_json::FldKey::operator !=(const lib_json::FldKey &rhs) const {
    return !lib_json::FldKey_Eq(const_cast<lib_json::FldKey&>(*this),const_cast<lib_json::FldKey&>(rhs));
}

// --- lib_json.FldKey..LtOp
inline bool lib_json::FldKey::operator <(const lib_json::FldKey &rhs) const {
    return lib_json::FldKey_Lt(const_cast<lib_json::FldKey&>(*this),const_cast<lib_json::FldKey&>(rhs));
}

// --- lib_json.FldKey..GtOp
inline bool lib_json::FldKey::operator >(const lib_json::FldKey &rhs) const {
    return lib_json::FldKey_Lt(const_cast<lib_json::FldKey&>(rhs),const_cast<lib_json::FldKey&>(*this));
}

// --- lib_json.FldKey..LeOp
inline bool lib_json::FldKey::operator <=(const lib_json::FldKey &rhs) const {
    return !lib_json::FldKey_Lt(const_cast<lib_json::FldKey&>(rhs),const_cast<lib_json::FldKey&>(*this));
}

// --- lib_json.FldKey..GeOp
inline bool lib_json::FldKey::operator >=(const lib_json::FldKey &rhs) const {
    return !lib_json::FldKey_Lt(const_cast<lib_json::FldKey&>(*this),const_cast<lib_json::FldKey&>(rhs));
}

// --- lib_json.FldKey..Lt
inline bool lib_json::FldKey_Lt(lib_json::FldKey& lhs, lib_json::FldKey& rhs) {
    return FldKey_Cmp(lhs,rhs) < 0;
}

// --- lib_json.FldKey..Cmp
inline i32 lib_json::FldKey_Cmp(lib_json::FldKey& lhs, lib_json::FldKey& rhs) {
    i32 retval = 0;
    retval = u64_Cmp((u64)(void*)lhs.object, (u64)(void*)rhs.object);
    if (retval != 0) {
        return retval;
    }
    retval = algo::strptr_Cmp(lhs.field, rhs.field);
    return retval;
}

// --- lib_json.FldKey..Init
// Set all fields to initial values.
inline void lib_json::FldKey_Init(lib_json::FldKey& parent) {
    parent.object = NULL;
}

// --- lib_json.FldKey..Eq
inline bool lib_json::FldKey_Eq(lib_json::FldKey& lhs, lib_json::FldKey& rhs) {
    bool retval = true;
    retval = u64_Eq((u64)(void*)lhs.object, (u64)(void*)rhs.object);
    if (!retval) {
        return false;
    }
    retval = algo::strptr_Eq(lhs.field, rhs.field);
    return retval;
}

// --- lib_json.FldKey..Update
// Set value. Return true if new value is different from old value.
inline bool lib_json::FldKey_Update(lib_json::FldKey &lhs, lib_json::FldKey& rhs) {
    bool ret = !FldKey_Eq(lhs, rhs); // compare values
    if (ret) {
        lhs = rhs; // update
    }
    return ret;
}

// --- lib_json.FldKey..Ctor
inline  lib_json::FldKey::FldKey() {
    lib_json::FldKey_Init(*this);
}

// --- lib_json.FldKey..FieldwiseCtor
inline  lib_json::FldKey::FldKey(lib_json::FNode* in_object, algo::strptr in_field)
    : object(in_object)
    , field(in_field)
 {
}

// --- lib_json.FNode.c_child.EmptyQ
// Return true if index is empty
inline bool lib_json::c_child_EmptyQ(lib_json::FNode& node) {
    return node.c_child_n == 0;
}

// --- lib_json.FNode.c_child.Find
// Look up row by row id. Return NULL if out of range
inline lib_json::FNode* lib_json::c_child_Find(lib_json::FNode& node, u32 t) {
    lib_json::FNode *retval = NULL;
    u64 idx = t;
    u64 lim = node.c_child_n;
    if (idx < lim) {
        retval = node.c_child_elems[idx];
    }
    return retval;
}

// --- lib_json.FNode.c_child.Getary
// Return array of pointers
inline algo::aryptr<lib_json::FNode*> lib_json::c_child_Getary(lib_json::FNode& node) {
    return algo::aryptr<lib_json::FNode*>(node.c_child_elems, node.c_child_n);
}

// --- lib_json.FNode.c_child.N
// Return number of items in the pointer array
inline i32 lib_json::c_child_N(const lib_json::FNode& node) {
    return node.c_child_n;
}

// --- lib_json.FNode.c_child.RemoveAll
// Empty the index. (The rows are not deleted)
inline void lib_json::c_child_RemoveAll(lib_json::FNode& node) {
    for (u32 i = 0; i < node.c_child_n; i++) {
        // mark all elements as not-in-array
        node.c_child_elems[i]->node_c_child_in_ary = false;
    }
    node.c_child_n = 0;
}

// --- lib_json.FNode.c_child.qFind
// Return reference without bounds checking
inline lib_json::FNode& lib_json::c_child_qFind(lib_json::FNode& node, u32 idx) {
    return *node.c_child_elems[idx];
}

// --- lib_json.FNode.c_child.InAryQ
// True if row is in any ptrary instance
inline bool lib_json::node_c_child_InAryQ(lib_json::FNode& row) {
    return row.node_c_child_in_ary;
}

// --- lib_json.FNode.c_child.qLast
// Reference to last element without bounds checking
inline lib_json::FNode& lib_json::c_child_qLast(lib_json::FNode& node) {
    return *node.c_child_elems[node.c_child_n-1];
}

// --- lib_json.FNode.type.GetEnum
// Get value of field as enum type
inline lib_json_FNode_type_Enum lib_json::type_GetEnum(const lib_json::FNode& node) {
    return lib_json_FNode_type_Enum(node.type);
}

// --- lib_json.FNode.type.SetEnum
// Set value of field from enum type.
inline void lib_json::type_SetEnum(lib_json::FNode& node, lib_json_FNode_type_Enum rhs) {
    node.type = u32(rhs);
}

// --- lib_json.FNode..Init
// Set all fields to initial values.
inline void lib_json::FNode_Init(lib_json::FNode& node) {
    node.p_parent = NULL;
    node.c_child_elems = NULL; // (lib_json.FNode.c_child)
    node.c_child_n = 0; // (lib_json.FNode.c_child)
    node.c_child_max = 0; // (lib_json.FNode.c_child)
    node.type = u32(0);
    node.node_c_child_in_ary = bool(false);
    node.node_next = (lib_json::FNode*)-1; // (lib_json.FDb.node) not-in-tpool's freelist
    node.ind_objfld_next = (lib_json::FNode*)-1; // (lib_json.FDb.ind_objfld) not-in-hash
}

// --- lib_json.FNode.c_child_curs.Reset
inline void lib_json::node_c_child_curs_Reset(node_c_child_curs &curs, lib_json::FNode &parent) {
    curs.elems = parent.c_child_elems;
    curs.n_elems = parent.c_child_n;
    curs.index = 0;
}

// --- lib_json.FNode.c_child_curs.ValidQ
// cursor points to valid item
inline bool lib_json::node_c_child_curs_ValidQ(node_c_child_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- lib_json.FNode.c_child_curs.Next
// proceed to next item
inline void lib_json::node_c_child_curs_Next(node_c_child_curs &curs) {
    curs.index++;
}

// --- lib_json.FNode.c_child_curs.Access
// item access
inline lib_json::FNode& lib_json::node_c_child_curs_Access(node_c_child_curs &curs) {
    return *curs.elems[curs.index];
}

// --- lib_json.FNode..Ctor
inline  lib_json::FNode::FNode() {
    lib_json::FNode_Init(*this);
}

// --- lib_json.FNode..Dtor
inline  lib_json::FNode::~FNode() {
    lib_json::FNode_Uninit(*this);
}

// --- lib_json.FParser.state.GetEnum
// Get value of field as enum type
inline lib_json_FParser_state_Enum lib_json::state_GetEnum(const lib_json::FParser& parent) {
    return lib_json_FParser_state_Enum(parent.state);
}

// --- lib_json.FParser.state.SetEnum
// Set value of field from enum type.
inline void lib_json::state_SetEnum(lib_json::FParser& parent, lib_json_FParser_state_Enum rhs) {
    parent.state = u32(rhs);
}

// --- lib_json.FParser..Ctor
inline  lib_json::FParser::FParser() {
    lib_json::FParser_Init(*this);
}

// --- lib_json.FParser..Dtor
inline  lib_json::FParser::~FParser() {
    lib_json::FParser_Uninit(*this);
}

// --- lib_json.FieldId.value.GetEnum
// Get value of field as enum type
inline lib_json_FieldIdEnum lib_json::value_GetEnum(const lib_json::FieldId& parent) {
    return lib_json_FieldIdEnum(parent.value);
}

// --- lib_json.FieldId.value.SetEnum
// Set value of field from enum type.
inline void lib_json::value_SetEnum(lib_json::FieldId& parent, lib_json_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- lib_json.FieldId.value.Cast
inline  lib_json::FieldId::operator lib_json_FieldIdEnum() const {
    return lib_json_FieldIdEnum((*this).value);
}

// --- lib_json.FieldId..Init
// Set all fields to initial values.
inline void lib_json::FieldId_Init(lib_json::FieldId& parent) {
    parent.value = i32(-1);
}

// --- lib_json.FieldId..Ctor
inline  lib_json::FieldId::FieldId() {
    lib_json::FieldId_Init(*this);
}

// --- lib_json.FieldId..FieldwiseCtor
inline  lib_json::FieldId::FieldId(i32 in_value)
    : value(in_value)
 {
}

// --- lib_json.FieldId..EnumCtor
inline  lib_json::FieldId::FieldId(lib_json_FieldIdEnum arg) {
    this->value = i32(arg);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_json::trace &row) {// cfmt:lib_json.trace.String
    lib_json::trace_Print(const_cast<lib_json::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_json::FldKey &row) {// cfmt:lib_json.FldKey.String
    lib_json::FldKey_Print(const_cast<lib_json::FldKey&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_json::FNode &row) {// cfmt:lib_json.FNode.String
    lib_json::FNode_Print(const_cast<lib_json::FNode&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_json::FParser &row) {// cfmt:lib_json.FParser.String
    lib_json::FParser_Print(const_cast<lib_json::FParser&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_json::FieldId &row) {// cfmt:lib_json.FieldId.String
    lib_json::FieldId_Print(const_cast<lib_json::FieldId&>(row), str);
    return str;
}
