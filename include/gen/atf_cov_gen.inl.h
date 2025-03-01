//
// include/gen/atf_cov_gen.inl.h
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
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude

// --- atf_cov.FCovfile..Init
// Set all fields to initial values.
inline void atf_cov::FCovfile_Init(atf_cov::FCovfile& covfile) {
    covfile.total = u32(0);
    covfile.nonexe = u32(0);
    covfile.exe = u32(0);
    covfile.hit = u32(0);
}

// --- atf_cov.FCovfile..Ctor
inline  atf_cov::FCovfile::FCovfile() {
    atf_cov::FCovfile_Init(*this);
}

// --- atf_cov.FCovfile..Dtor
inline  atf_cov::FCovfile::~FCovfile() {
    atf_cov::FCovfile_Uninit(*this);
}

// --- atf_cov.FCovline..Init
// Set all fields to initial values.
inline void atf_cov::FCovline_Init(atf_cov::FCovline& covline) {
    covline.flag = char('N');
    covline.hit = u32(0);
    covline.p_gitfile = NULL;
    covline.gitfile_c_covline_in_ary = bool(false);
    covline.ind_covline_next = (atf_cov::FCovline*)-1; // (atf_cov.FDb.ind_covline) not-in-hash
}

// --- atf_cov.FCovline..Ctor
inline  atf_cov::FCovline::FCovline() {
    atf_cov::FCovline_Init(*this);
}

// --- atf_cov.FCovline..Dtor
inline  atf_cov::FCovline::~FCovline() {
    atf_cov::FCovline_Uninit(*this);
}

// --- atf_cov.FCovtarget..Init
// Set all fields to initial values.
inline void atf_cov::FCovtarget_Init(atf_cov::FCovtarget& covtarget) {
    covtarget.total = u32(0);
    covtarget.nonexe = u32(0);
    covtarget.exe = u32(0);
    covtarget.hit = u32(0);
}

// --- atf_cov.FCovtarget..Ctor
inline  atf_cov::FCovtarget::FCovtarget() {
    atf_cov::FCovtarget_Init(*this);
}

// --- atf_cov.FCovtarget..Dtor
inline  atf_cov::FCovtarget::~FCovtarget() {
    atf_cov::FCovtarget_Uninit(*this);
}

// --- atf_cov.trace..Ctor
inline  atf_cov::trace::trace() {
}

// --- atf_cov.FDb.covline.EmptyQ
// Return true if index is empty
inline bool atf_cov::covline_EmptyQ() {
    return _db.covline_n == 0;
}

// --- atf_cov.FDb.covline.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FCovline* atf_cov::covline_Find(u64 t) {
    atf_cov::FCovline *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.covline_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.covline_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.covline.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FCovline* atf_cov::covline_Last() {
    return covline_Find(u64(_db.covline_n-1));
}

// --- atf_cov.FDb.covline.N
// Return number of items in the pool
inline i32 atf_cov::covline_N() {
    return _db.covline_n;
}

// --- atf_cov.FDb.covline.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FCovline& atf_cov::covline_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.covline_lary[bsr][index];
}

// --- atf_cov.FDb.ind_covline.EmptyQ
// Return true if hash is empty
inline bool atf_cov::ind_covline_EmptyQ() {
    return _db.ind_covline_n == 0;
}

// --- atf_cov.FDb.ind_covline.N
// Return number of items in the hash
inline i32 atf_cov::ind_covline_N() {
    return _db.ind_covline_n;
}

// --- atf_cov.FDb.target.EmptyQ
// Return true if index is empty
inline bool atf_cov::target_EmptyQ() {
    return _db.target_n == 0;
}

// --- atf_cov.FDb.target.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FTarget* atf_cov::target_Find(u64 t) {
    atf_cov::FTarget *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.target_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.target_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.target.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FTarget* atf_cov::target_Last() {
    return target_Find(u64(_db.target_n-1));
}

// --- atf_cov.FDb.target.N
// Return number of items in the pool
inline i32 atf_cov::target_N() {
    return _db.target_n;
}

// --- atf_cov.FDb.target.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FTarget& atf_cov::target_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.target_lary[bsr][index];
}

// --- atf_cov.FDb.ind_target.EmptyQ
// Return true if hash is empty
inline bool atf_cov::ind_target_EmptyQ() {
    return _db.ind_target_n == 0;
}

// --- atf_cov.FDb.ind_target.N
// Return number of items in the hash
inline i32 atf_cov::ind_target_N() {
    return _db.ind_target_n;
}

// --- atf_cov.FDb.targsrc.EmptyQ
// Return true if index is empty
inline bool atf_cov::targsrc_EmptyQ() {
    return _db.targsrc_n == 0;
}

// --- atf_cov.FDb.targsrc.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FTargsrc* atf_cov::targsrc_Find(u64 t) {
    atf_cov::FTargsrc *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.targsrc_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.targsrc_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.targsrc.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FTargsrc* atf_cov::targsrc_Last() {
    return targsrc_Find(u64(_db.targsrc_n-1));
}

// --- atf_cov.FDb.targsrc.N
// Return number of items in the pool
inline i32 atf_cov::targsrc_N() {
    return _db.targsrc_n;
}

// --- atf_cov.FDb.targsrc.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FTargsrc& atf_cov::targsrc_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.targsrc_lary[bsr][index];
}

// --- atf_cov.FDb.ind_targsrc.EmptyQ
// Return true if hash is empty
inline bool atf_cov::ind_targsrc_EmptyQ() {
    return _db.ind_targsrc_n == 0;
}

// --- atf_cov.FDb.ind_targsrc.N
// Return number of items in the hash
inline i32 atf_cov::ind_targsrc_N() {
    return _db.ind_targsrc_n;
}

// --- atf_cov.FDb.gitfile.EmptyQ
// Return true if index is empty
inline bool atf_cov::gitfile_EmptyQ() {
    return _db.gitfile_n == 0;
}

// --- atf_cov.FDb.gitfile.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FGitfile* atf_cov::gitfile_Find(u64 t) {
    atf_cov::FGitfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.gitfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.gitfile_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.gitfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FGitfile* atf_cov::gitfile_Last() {
    return gitfile_Find(u64(_db.gitfile_n-1));
}

// --- atf_cov.FDb.gitfile.N
// Return number of items in the pool
inline i32 atf_cov::gitfile_N() {
    return _db.gitfile_n;
}

// --- atf_cov.FDb.gitfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FGitfile& atf_cov::gitfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.gitfile_lary[bsr][index];
}

// --- atf_cov.FDb.ind_gitfile.EmptyQ
// Return true if hash is empty
inline bool atf_cov::ind_gitfile_EmptyQ() {
    return _db.ind_gitfile_n == 0;
}

// --- atf_cov.FDb.ind_gitfile.N
// Return number of items in the hash
inline i32 atf_cov::ind_gitfile_N() {
    return _db.ind_gitfile_n;
}

// --- atf_cov.FDb.covtarget.EmptyQ
// Return true if index is empty
inline bool atf_cov::covtarget_EmptyQ() {
    return _db.covtarget_n == 0;
}

// --- atf_cov.FDb.covtarget.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FCovtarget* atf_cov::covtarget_Find(u64 t) {
    atf_cov::FCovtarget *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.covtarget_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.covtarget_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.covtarget.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FCovtarget* atf_cov::covtarget_Last() {
    return covtarget_Find(u64(_db.covtarget_n-1));
}

// --- atf_cov.FDb.covtarget.N
// Return number of items in the pool
inline i32 atf_cov::covtarget_N() {
    return _db.covtarget_n;
}

// --- atf_cov.FDb.covtarget.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FCovtarget& atf_cov::covtarget_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.covtarget_lary[bsr][index];
}

// --- atf_cov.FDb.covfile.EmptyQ
// Return true if index is empty
inline bool atf_cov::covfile_EmptyQ() {
    return _db.covfile_n == 0;
}

// --- atf_cov.FDb.covfile.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FCovfile* atf_cov::covfile_Find(u64 t) {
    atf_cov::FCovfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.covfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.covfile_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.covfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FCovfile* atf_cov::covfile_Last() {
    return covfile_Find(u64(_db.covfile_n-1));
}

// --- atf_cov.FDb.covfile.N
// Return number of items in the pool
inline i32 atf_cov::covfile_N() {
    return _db.covfile_n;
}

// --- atf_cov.FDb.covfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FCovfile& atf_cov::covfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.covfile_lary[bsr][index];
}

// --- atf_cov.FDb.tgtcov.EmptyQ
// Return true if index is empty
inline bool atf_cov::tgtcov_EmptyQ() {
    return _db.tgtcov_n == 0;
}

// --- atf_cov.FDb.tgtcov.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FTgtcov* atf_cov::tgtcov_Find(u64 t) {
    atf_cov::FTgtcov *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.tgtcov_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.tgtcov_lary[bsr][index];
    }
    return retval;
}

// --- atf_cov.FDb.tgtcov.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_cov::FTgtcov* atf_cov::tgtcov_Last() {
    return tgtcov_Find(u64(_db.tgtcov_n-1));
}

// --- atf_cov.FDb.tgtcov.N
// Return number of items in the pool
inline i32 atf_cov::tgtcov_N() {
    return _db.tgtcov_n;
}

// --- atf_cov.FDb.tgtcov.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_cov::FTgtcov& atf_cov::tgtcov_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.tgtcov_lary[bsr][index];
}

// --- atf_cov.FDb.ind_tgtcov.EmptyQ
// Return true if hash is empty
inline bool atf_cov::ind_tgtcov_EmptyQ() {
    return _db.ind_tgtcov_n == 0;
}

// --- atf_cov.FDb.ind_tgtcov.N
// Return number of items in the hash
inline i32 atf_cov::ind_tgtcov_N() {
    return _db.ind_tgtcov_n;
}

// --- atf_cov.FDb.covline_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_covline_curs_Reset(_db_covline_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.covline_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_covline_curs_ValidQ(_db_covline_curs &curs) {
    return curs.index < _db.covline_n;
}

// --- atf_cov.FDb.covline_curs.Next
// proceed to next item
inline void atf_cov::_db_covline_curs_Next(_db_covline_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.covline_curs.Access
// item access
inline atf_cov::FCovline& atf_cov::_db_covline_curs_Access(_db_covline_curs &curs) {
    return covline_qFind(u64(curs.index));
}

// --- atf_cov.FDb.target_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_target_curs_Reset(_db_target_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.target_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_target_curs_ValidQ(_db_target_curs &curs) {
    return curs.index < _db.target_n;
}

// --- atf_cov.FDb.target_curs.Next
// proceed to next item
inline void atf_cov::_db_target_curs_Next(_db_target_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.target_curs.Access
// item access
inline atf_cov::FTarget& atf_cov::_db_target_curs_Access(_db_target_curs &curs) {
    return target_qFind(u64(curs.index));
}

// --- atf_cov.FDb.targsrc_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_targsrc_curs_Reset(_db_targsrc_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.targsrc_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_targsrc_curs_ValidQ(_db_targsrc_curs &curs) {
    return curs.index < _db.targsrc_n;
}

// --- atf_cov.FDb.targsrc_curs.Next
// proceed to next item
inline void atf_cov::_db_targsrc_curs_Next(_db_targsrc_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.targsrc_curs.Access
// item access
inline atf_cov::FTargsrc& atf_cov::_db_targsrc_curs_Access(_db_targsrc_curs &curs) {
    return targsrc_qFind(u64(curs.index));
}

// --- atf_cov.FDb.gitfile_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_gitfile_curs_Reset(_db_gitfile_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.gitfile_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_gitfile_curs_ValidQ(_db_gitfile_curs &curs) {
    return curs.index < _db.gitfile_n;
}

// --- atf_cov.FDb.gitfile_curs.Next
// proceed to next item
inline void atf_cov::_db_gitfile_curs_Next(_db_gitfile_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.gitfile_curs.Access
// item access
inline atf_cov::FGitfile& atf_cov::_db_gitfile_curs_Access(_db_gitfile_curs &curs) {
    return gitfile_qFind(u64(curs.index));
}

// --- atf_cov.FDb.covtarget_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_covtarget_curs_Reset(_db_covtarget_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.covtarget_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_covtarget_curs_ValidQ(_db_covtarget_curs &curs) {
    return curs.index < _db.covtarget_n;
}

// --- atf_cov.FDb.covtarget_curs.Next
// proceed to next item
inline void atf_cov::_db_covtarget_curs_Next(_db_covtarget_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.covtarget_curs.Access
// item access
inline atf_cov::FCovtarget& atf_cov::_db_covtarget_curs_Access(_db_covtarget_curs &curs) {
    return covtarget_qFind(u64(curs.index));
}

// --- atf_cov.FDb.covfile_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_covfile_curs_Reset(_db_covfile_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.covfile_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_covfile_curs_ValidQ(_db_covfile_curs &curs) {
    return curs.index < _db.covfile_n;
}

// --- atf_cov.FDb.covfile_curs.Next
// proceed to next item
inline void atf_cov::_db_covfile_curs_Next(_db_covfile_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.covfile_curs.Access
// item access
inline atf_cov::FCovfile& atf_cov::_db_covfile_curs_Access(_db_covfile_curs &curs) {
    return covfile_qFind(u64(curs.index));
}

// --- atf_cov.FDb.tgtcov_curs.Reset
// cursor points to valid item
inline void atf_cov::_db_tgtcov_curs_Reset(_db_tgtcov_curs &curs, atf_cov::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_cov.FDb.tgtcov_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::_db_tgtcov_curs_ValidQ(_db_tgtcov_curs &curs) {
    return curs.index < _db.tgtcov_n;
}

// --- atf_cov.FDb.tgtcov_curs.Next
// proceed to next item
inline void atf_cov::_db_tgtcov_curs_Next(_db_tgtcov_curs &curs) {
    curs.index++;
}

// --- atf_cov.FDb.tgtcov_curs.Access
// item access
inline atf_cov::FTgtcov& atf_cov::_db_tgtcov_curs_Access(_db_tgtcov_curs &curs) {
    return tgtcov_qFind(u64(curs.index));
}

// --- atf_cov.FGitfile.c_targsrc.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_cov::c_targsrc_InsertMaybe(atf_cov::FGitfile& gitfile, atf_cov::FTargsrc& row) {
    atf_cov::FTargsrc* ptr = gitfile.c_targsrc;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_targsrc = &row;
    }
    return retval;
}

// --- atf_cov.FGitfile.c_targsrc.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_cov::c_targsrc_Remove(atf_cov::FGitfile& gitfile, atf_cov::FTargsrc& row) {
    atf_cov::FTargsrc *ptr = gitfile.c_targsrc;
    if (LIKELY(ptr == &row)) {
        gitfile.c_targsrc = NULL;
    }
}

// --- atf_cov.FGitfile.c_covline.EmptyQ
// Return true if index is empty
inline bool atf_cov::c_covline_EmptyQ(atf_cov::FGitfile& gitfile) {
    return gitfile.c_covline_n == 0;
}

// --- atf_cov.FGitfile.c_covline.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FCovline* atf_cov::c_covline_Find(atf_cov::FGitfile& gitfile, u32 t) {
    atf_cov::FCovline *retval = NULL;
    u64 idx = t;
    u64 lim = gitfile.c_covline_n;
    if (idx < lim) {
        retval = gitfile.c_covline_elems[idx];
    }
    return retval;
}

// --- atf_cov.FGitfile.c_covline.Getary
// Return array of pointers
inline algo::aryptr<atf_cov::FCovline*> atf_cov::c_covline_Getary(atf_cov::FGitfile& gitfile) {
    return algo::aryptr<atf_cov::FCovline*>(gitfile.c_covline_elems, gitfile.c_covline_n);
}

// --- atf_cov.FGitfile.c_covline.N
// Return number of items in the pointer array
inline i32 atf_cov::c_covline_N(const atf_cov::FGitfile& gitfile) {
    return gitfile.c_covline_n;
}

// --- atf_cov.FGitfile.c_covline.RemoveAll
// Empty the index. (The rows are not deleted)
inline void atf_cov::c_covline_RemoveAll(atf_cov::FGitfile& gitfile) {
    for (u32 i = 0; i < gitfile.c_covline_n; i++) {
        // mark all elements as not-in-array
        gitfile.c_covline_elems[i]->gitfile_c_covline_in_ary = false;
    }
    gitfile.c_covline_n = 0;
}

// --- atf_cov.FGitfile.c_covline.qFind
// Return reference without bounds checking
inline atf_cov::FCovline& atf_cov::c_covline_qFind(atf_cov::FGitfile& gitfile, u32 idx) {
    return *gitfile.c_covline_elems[idx];
}

// --- atf_cov.FGitfile.c_covline.InAryQ
// True if row is in any ptrary instance
inline bool atf_cov::gitfile_c_covline_InAryQ(atf_cov::FCovline& row) {
    return row.gitfile_c_covline_in_ary;
}

// --- atf_cov.FGitfile.c_covline.qLast
// Reference to last element without bounds checking
inline atf_cov::FCovline& atf_cov::c_covline_qLast(atf_cov::FGitfile& gitfile) {
    return *gitfile.c_covline_elems[gitfile.c_covline_n-1];
}

// --- atf_cov.FGitfile.c_covfile.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_cov::c_covfile_InsertMaybe(atf_cov::FGitfile& gitfile, atf_cov::FCovfile& row) {
    atf_cov::FCovfile* ptr = gitfile.c_covfile;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_covfile = &row;
    }
    return retval;
}

// --- atf_cov.FGitfile.c_covfile.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_cov::c_covfile_Remove(atf_cov::FGitfile& gitfile, atf_cov::FCovfile& row) {
    atf_cov::FCovfile *ptr = gitfile.c_covfile;
    if (LIKELY(ptr == &row)) {
        gitfile.c_covfile = NULL;
    }
}

// --- atf_cov.FGitfile..Init
// Set all fields to initial values.
inline void atf_cov::FGitfile_Init(atf_cov::FGitfile& gitfile) {
    gitfile.c_targsrc = NULL;
    gitfile.c_covline_elems = NULL; // (atf_cov.FGitfile.c_covline)
    gitfile.c_covline_n = 0; // (atf_cov.FGitfile.c_covline)
    gitfile.c_covline_max = 0; // (atf_cov.FGitfile.c_covline)
    gitfile.c_covfile = NULL;
    gitfile.ind_gitfile_next = (atf_cov::FGitfile*)-1; // (atf_cov.FDb.ind_gitfile) not-in-hash
}

// --- atf_cov.FGitfile.c_covline_curs.Reset
inline void atf_cov::gitfile_c_covline_curs_Reset(gitfile_c_covline_curs &curs, atf_cov::FGitfile &parent) {
    curs.elems = parent.c_covline_elems;
    curs.n_elems = parent.c_covline_n;
    curs.index = 0;
}

// --- atf_cov.FGitfile.c_covline_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::gitfile_c_covline_curs_ValidQ(gitfile_c_covline_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- atf_cov.FGitfile.c_covline_curs.Next
// proceed to next item
inline void atf_cov::gitfile_c_covline_curs_Next(gitfile_c_covline_curs &curs) {
    curs.index++;
}

// --- atf_cov.FGitfile.c_covline_curs.Access
// item access
inline atf_cov::FCovline& atf_cov::gitfile_c_covline_curs_Access(gitfile_c_covline_curs &curs) {
    return *curs.elems[curs.index];
}

// --- atf_cov.FGitfile..Ctor
inline  atf_cov::FGitfile::FGitfile() {
    atf_cov::FGitfile_Init(*this);
}

// --- atf_cov.FGitfile..Dtor
inline  atf_cov::FGitfile::~FGitfile() {
    atf_cov::FGitfile_Uninit(*this);
}

// --- atf_cov.FTarget.c_targsrc.EmptyQ
// Return true if index is empty
inline bool atf_cov::c_targsrc_EmptyQ(atf_cov::FTarget& target) {
    return target.c_targsrc_n == 0;
}

// --- atf_cov.FTarget.c_targsrc.Find
// Look up row by row id. Return NULL if out of range
inline atf_cov::FTargsrc* atf_cov::c_targsrc_Find(atf_cov::FTarget& target, u32 t) {
    atf_cov::FTargsrc *retval = NULL;
    u64 idx = t;
    u64 lim = target.c_targsrc_n;
    if (idx < lim) {
        retval = target.c_targsrc_elems[idx];
    }
    return retval;
}

// --- atf_cov.FTarget.c_targsrc.Getary
// Return array of pointers
inline algo::aryptr<atf_cov::FTargsrc*> atf_cov::c_targsrc_Getary(atf_cov::FTarget& target) {
    return algo::aryptr<atf_cov::FTargsrc*>(target.c_targsrc_elems, target.c_targsrc_n);
}

// --- atf_cov.FTarget.c_targsrc.N
// Return number of items in the pointer array
inline i32 atf_cov::c_targsrc_N(const atf_cov::FTarget& target) {
    return target.c_targsrc_n;
}

// --- atf_cov.FTarget.c_targsrc.RemoveAll
// Empty the index. (The rows are not deleted)
inline void atf_cov::c_targsrc_RemoveAll(atf_cov::FTarget& target) {
    for (u32 i = 0; i < target.c_targsrc_n; i++) {
        // mark all elements as not-in-array
        target.c_targsrc_elems[i]->target_c_targsrc_in_ary = false;
    }
    target.c_targsrc_n = 0;
}

// --- atf_cov.FTarget.c_targsrc.qFind
// Return reference without bounds checking
inline atf_cov::FTargsrc& atf_cov::c_targsrc_qFind(atf_cov::FTarget& target, u32 idx) {
    return *target.c_targsrc_elems[idx];
}

// --- atf_cov.FTarget.c_targsrc.InAryQ
// True if row is in any ptrary instance
inline bool atf_cov::target_c_targsrc_InAryQ(atf_cov::FTargsrc& row) {
    return row.target_c_targsrc_in_ary;
}

// --- atf_cov.FTarget.c_targsrc.qLast
// Reference to last element without bounds checking
inline atf_cov::FTargsrc& atf_cov::c_targsrc_qLast(atf_cov::FTarget& target) {
    return *target.c_targsrc_elems[target.c_targsrc_n-1];
}

// --- atf_cov.FTarget.c_covtarget.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_cov::c_covtarget_InsertMaybe(atf_cov::FTarget& target, atf_cov::FCovtarget& row) {
    atf_cov::FCovtarget* ptr = target.c_covtarget;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        target.c_covtarget = &row;
    }
    return retval;
}

// --- atf_cov.FTarget.c_covtarget.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_cov::c_covtarget_Remove(atf_cov::FTarget& target, atf_cov::FCovtarget& row) {
    atf_cov::FCovtarget *ptr = target.c_covtarget;
    if (LIKELY(ptr == &row)) {
        target.c_covtarget = NULL;
    }
}

// --- atf_cov.FTarget.c_tgtcov.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool atf_cov::c_tgtcov_InsertMaybe(atf_cov::FTarget& target, atf_cov::FTgtcov& row) {
    atf_cov::FTgtcov* ptr = target.c_tgtcov;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        target.c_tgtcov = &row;
    }
    return retval;
}

// --- atf_cov.FTarget.c_tgtcov.Remove
// Remove element from index. If element is not in index, do nothing.
inline void atf_cov::c_tgtcov_Remove(atf_cov::FTarget& target, atf_cov::FTgtcov& row) {
    atf_cov::FTgtcov *ptr = target.c_tgtcov;
    if (LIKELY(ptr == &row)) {
        target.c_tgtcov = NULL;
    }
}

// --- atf_cov.FTarget..Init
// Set all fields to initial values.
inline void atf_cov::FTarget_Init(atf_cov::FTarget& target) {
    target.c_targsrc_elems = NULL; // (atf_cov.FTarget.c_targsrc)
    target.c_targsrc_n = 0; // (atf_cov.FTarget.c_targsrc)
    target.c_targsrc_max = 0; // (atf_cov.FTarget.c_targsrc)
    target.c_covtarget = NULL;
    target.c_tgtcov = NULL;
    target.ind_target_next = (atf_cov::FTarget*)-1; // (atf_cov.FDb.ind_target) not-in-hash
}

// --- atf_cov.FTarget.c_targsrc_curs.Reset
inline void atf_cov::target_c_targsrc_curs_Reset(target_c_targsrc_curs &curs, atf_cov::FTarget &parent) {
    curs.elems = parent.c_targsrc_elems;
    curs.n_elems = parent.c_targsrc_n;
    curs.index = 0;
}

// --- atf_cov.FTarget.c_targsrc_curs.ValidQ
// cursor points to valid item
inline bool atf_cov::target_c_targsrc_curs_ValidQ(target_c_targsrc_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- atf_cov.FTarget.c_targsrc_curs.Next
// proceed to next item
inline void atf_cov::target_c_targsrc_curs_Next(target_c_targsrc_curs &curs) {
    curs.index++;
}

// --- atf_cov.FTarget.c_targsrc_curs.Access
// item access
inline atf_cov::FTargsrc& atf_cov::target_c_targsrc_curs_Access(target_c_targsrc_curs &curs) {
    return *curs.elems[curs.index];
}

// --- atf_cov.FTarget..Ctor
inline  atf_cov::FTarget::FTarget() {
    atf_cov::FTarget_Init(*this);
}

// --- atf_cov.FTarget..Dtor
inline  atf_cov::FTarget::~FTarget() {
    atf_cov::FTarget_Uninit(*this);
}

// --- atf_cov.FTargsrc..Init
// Set all fields to initial values.
inline void atf_cov::FTargsrc_Init(atf_cov::FTargsrc& targsrc) {
    targsrc.p_gitfile = NULL;
    targsrc.p_target = NULL;
    targsrc.target_c_targsrc_in_ary = bool(false);
    targsrc.ind_targsrc_next = (atf_cov::FTargsrc*)-1; // (atf_cov.FDb.ind_targsrc) not-in-hash
}

// --- atf_cov.FTargsrc..Ctor
inline  atf_cov::FTargsrc::FTargsrc() {
    atf_cov::FTargsrc_Init(*this);
}

// --- atf_cov.FTargsrc..Dtor
inline  atf_cov::FTargsrc::~FTargsrc() {
    atf_cov::FTargsrc_Uninit(*this);
}

// --- atf_cov.FTgtcov..Init
// Set all fields to initial values.
inline void atf_cov::FTgtcov_Init(atf_cov::FTgtcov& tgtcov) {
    tgtcov.ind_tgtcov_next = (atf_cov::FTgtcov*)-1; // (atf_cov.FDb.ind_tgtcov) not-in-hash
}

// --- atf_cov.FTgtcov..Ctor
inline  atf_cov::FTgtcov::FTgtcov() {
    atf_cov::FTgtcov_Init(*this);
}

// --- atf_cov.FTgtcov..Dtor
inline  atf_cov::FTgtcov::~FTgtcov() {
    atf_cov::FTgtcov_Uninit(*this);
}

// --- atf_cov.FieldId.value.GetEnum
// Get value of field as enum type
inline atf_cov_FieldIdEnum atf_cov::value_GetEnum(const atf_cov::FieldId& parent) {
    return atf_cov_FieldIdEnum(parent.value);
}

// --- atf_cov.FieldId.value.SetEnum
// Set value of field from enum type.
inline void atf_cov::value_SetEnum(atf_cov::FieldId& parent, atf_cov_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- atf_cov.FieldId.value.Cast
inline  atf_cov::FieldId::operator atf_cov_FieldIdEnum() const {
    return atf_cov_FieldIdEnum((*this).value);
}

// --- atf_cov.FieldId..Init
// Set all fields to initial values.
inline void atf_cov::FieldId_Init(atf_cov::FieldId& parent) {
    parent.value = i32(-1);
}

// --- atf_cov.FieldId..Ctor
inline  atf_cov::FieldId::FieldId() {
    atf_cov::FieldId_Init(*this);
}

// --- atf_cov.FieldId..FieldwiseCtor
inline  atf_cov::FieldId::FieldId(i32 in_value)
    : value(in_value)
 {
}

// --- atf_cov.FieldId..EnumCtor
inline  atf_cov::FieldId::FieldId(atf_cov_FieldIdEnum arg) {
    this->value = i32(arg);
}

// --- atf_cov.Phase.value.GetEnum
// Get value of field as enum type
inline atf_cov_Phase_value_Enum atf_cov::value_GetEnum(const atf_cov::Phase& parent) {
    return atf_cov_Phase_value_Enum(parent.value);
}

// --- atf_cov.Phase.value.SetEnum
// Set value of field from enum type.
inline void atf_cov::value_SetEnum(atf_cov::Phase& parent, atf_cov_Phase_value_Enum rhs) {
    parent.value = u8(rhs);
}

// --- atf_cov.Phase..EqOp
inline bool atf_cov::Phase::operator ==(const atf_cov::Phase &rhs) const {
    return atf_cov::Phase_Eq(const_cast<atf_cov::Phase&>(*this),const_cast<atf_cov::Phase&>(rhs));
}

// --- atf_cov.Phase..NeOp
inline bool atf_cov::Phase::operator !=(const atf_cov::Phase &rhs) const {
    return !atf_cov::Phase_Eq(const_cast<atf_cov::Phase&>(*this),const_cast<atf_cov::Phase&>(rhs));
}

// --- atf_cov.Phase..LtOp
inline bool atf_cov::Phase::operator <(const atf_cov::Phase &rhs) const {
    return atf_cov::Phase_Lt(const_cast<atf_cov::Phase&>(*this),const_cast<atf_cov::Phase&>(rhs));
}

// --- atf_cov.Phase..GtOp
inline bool atf_cov::Phase::operator >(const atf_cov::Phase &rhs) const {
    return atf_cov::Phase_Lt(const_cast<atf_cov::Phase&>(rhs),const_cast<atf_cov::Phase&>(*this));
}

// --- atf_cov.Phase..LeOp
inline bool atf_cov::Phase::operator <=(const atf_cov::Phase &rhs) const {
    return !atf_cov::Phase_Lt(const_cast<atf_cov::Phase&>(rhs),const_cast<atf_cov::Phase&>(*this));
}

// --- atf_cov.Phase..GeOp
inline bool atf_cov::Phase::operator >=(const atf_cov::Phase &rhs) const {
    return !atf_cov::Phase_Lt(const_cast<atf_cov::Phase&>(*this),const_cast<atf_cov::Phase&>(rhs));
}

// --- atf_cov.Phase..Lt
inline bool atf_cov::Phase_Lt(atf_cov::Phase lhs, atf_cov::Phase rhs) {
    return u8_Lt(lhs.value, rhs.value);
}

// --- atf_cov.Phase..Cmp
inline i32 atf_cov::Phase_Cmp(atf_cov::Phase lhs, atf_cov::Phase rhs) {
    i32 retval = 0;
    retval = u8_Cmp(lhs.value, rhs.value);
    return retval;
}

// --- atf_cov.Phase..Init
// Set all fields to initial values.
inline void atf_cov::Phase_Init(atf_cov::Phase& parent) {
    parent.value = u8(0);
}

// --- atf_cov.Phase..UpdateMax
// Attempt to make LHS bigger. Return true if it was changed
inline bool atf_cov::Phase_UpdateMax(atf_cov::Phase &lhs, atf_cov::Phase rhs) {
    bool retval = lhs < rhs;
    if (retval) {
        lhs = rhs;
    }
    return retval;
}

// --- atf_cov.Phase..Min
// Return the lesser of two values
inline atf_cov::Phase atf_cov::Phase_Min(atf_cov::Phase lhs, atf_cov::Phase rhs) {
    return lhs < rhs ? lhs : rhs;
}

// --- atf_cov.Phase..UpdateMin
// Attempt to make LHS smaller. Return true if it was changed
inline bool atf_cov::Phase_UpdateMin(atf_cov::Phase &lhs, atf_cov::Phase rhs) {
    bool retval = rhs < lhs;
    if (retval) {
        lhs = rhs;
    }
    return retval;
}

// --- atf_cov.Phase..Max
// Return the greater of two values
inline atf_cov::Phase atf_cov::Phase_Max(atf_cov::Phase lhs, atf_cov::Phase rhs) {
    return rhs < lhs ? lhs : rhs;
}

// --- atf_cov.Phase..Eq
inline bool atf_cov::Phase_Eq(atf_cov::Phase lhs, atf_cov::Phase rhs) {
    bool retval = true;
    retval = u8_Eq(lhs.value, rhs.value);
    return retval;
}

// --- atf_cov.Phase..Update
// Set value. Return true if new value is different from old value.
inline bool atf_cov::Phase_Update(atf_cov::Phase &lhs, atf_cov::Phase rhs) {
    bool ret = !Phase_Eq(lhs, rhs); // compare values
    if (ret) {
        lhs = rhs; // update
    }
    return ret;
}

// --- atf_cov.Phase..EqEnum
// define enum comparison operator to avoid ambiguity
inline bool atf_cov::Phase::operator ==(atf_cov_Phase_value_Enum rhs) const {
    return atf_cov_Phase_value_Enum(value) == rhs;
}

// --- atf_cov.Phase..Ctor
inline  atf_cov::Phase::Phase() {
    atf_cov::Phase_Init(*this);
}

// --- atf_cov.Phase..EnumCtor
inline  atf_cov::Phase::Phase(atf_cov_Phase_value_Enum arg) {
    this->value = u8(arg);
}

// --- atf_cov.TableId.value.GetEnum
// Get value of field as enum type
inline atf_cov_TableIdEnum atf_cov::value_GetEnum(const atf_cov::TableId& parent) {
    return atf_cov_TableIdEnum(parent.value);
}

// --- atf_cov.TableId.value.SetEnum
// Set value of field from enum type.
inline void atf_cov::value_SetEnum(atf_cov::TableId& parent, atf_cov_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- atf_cov.TableId.value.Cast
inline  atf_cov::TableId::operator atf_cov_TableIdEnum() const {
    return atf_cov_TableIdEnum((*this).value);
}

// --- atf_cov.TableId..Init
// Set all fields to initial values.
inline void atf_cov::TableId_Init(atf_cov::TableId& parent) {
    parent.value = i32(-1);
}

// --- atf_cov.TableId..Ctor
inline  atf_cov::TableId::TableId() {
    atf_cov::TableId_Init(*this);
}

// --- atf_cov.TableId..FieldwiseCtor
inline  atf_cov::TableId::TableId(i32 in_value)
    : value(in_value)
 {
}

// --- atf_cov.TableId..EnumCtor
inline  atf_cov::TableId::TableId(atf_cov_TableIdEnum arg) {
    this->value = i32(arg);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_cov::FCovline &row) {// cfmt:atf_cov.FCovline.String
    atf_cov::FCovline_Print(const_cast<atf_cov::FCovline&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_cov::trace &row) {// cfmt:atf_cov.trace.String
    atf_cov::trace_Print(const_cast<atf_cov::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_cov::FieldId &row) {// cfmt:atf_cov.FieldId.String
    atf_cov::FieldId_Print(const_cast<atf_cov::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_cov::Phase &row) {// cfmt:atf_cov.Phase.String
    atf_cov::Phase_Print(const_cast<atf_cov::Phase&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_cov::TableId &row) {// cfmt:atf_cov.TableId.String
    atf_cov::TableId_Print(const_cast<atf_cov::TableId&>(row), str);
    return str;
}
