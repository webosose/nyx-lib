// Copyright (c) 2010-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef __NYX__LOG_H__
#define __NYX__LOG_H__

#include <PmLogLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Logging for nyx main context ********
 * The parameters needed are
 * msgid - unique message id
 * kvcount - count for key-value pairs
 * ... - key-value pairs and free text. key-value pairs are formed using PMLOGKS or PMLOGKFV
 * e.g.)
 * nyx_critical(msgid, 2, PMLOGKS("key1", "value1"), PMLOGKFV"key2", "%s", value2), "free text message");
 **********************************************/

#define nyx_critical(msgid, kvcount, ...) \
        PmLogCritical(getNyxContext(), msgid, kvcount, ##__VA_ARGS__)

#define nyx_error(msgid, kvcount, ...) \
        PmLogError(getNyxContext(), msgid, kvcount,##__VA_ARGS__)

#define nyx_warn(msgid, kvcount, ...) \
        PmLogWarning(getNyxContext(), msgid, kvcount, ##__VA_ARGS__)

#define nyx_info(msgid, kvcount, ...) \
        PmLogInfo(getNyxContext(), msgid, kvcount, ##__VA_ARGS__)

#define nyx_debug(...) \
        PmLogDebug(getNyxContext(), ##__VA_ARGS__)

extern PmLogContext getNyxContext();

#ifdef __cplusplus
} //extern "C"
#endif

#endif // __NYX__LOG_H__

