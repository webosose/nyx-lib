// Copyright (c) 2016-2018 LG Electronics, Inc.
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

#ifndef NYXLIB_MSG__LOG_H__
#define NYXLIB_MSG__LOG_H__


/** errors with nyx_device_impl */
#define MSGID_NYX_DEVICE_OPEN_ERR                                            "NYX_DEVICE_OPEN_ERR"
#define MSGID_NYX_DEVICE_WRONG_EVENT_TYPE                                    "NYX_WRONG_EVENT_TYPE"
#define MSGID_NYX_DEVICE_WRONG_DEVICE                                        "NYX_WRONG_DEVICE_ERR"
#define MSGID_NYX_DEVICE_INVALID_HANDLE                                      "NYX_INVALID_HANDLE_ERR"
#define MSGID_NYX_DEVICE_INVALID_EVENT                                       "NYX_INVALID_EVENT_ERR"

/** nyx utils read write errors */
#define MSGID_NYX_UTIL_WRITE_ERR                                             "NYX_WRITE_ERR"
#define MSGID_NYX_UTIL_WRITE_VAL_ERR                                         "NYX_WRITE_VAL_ERR"
#define MSGID_NYX_CALLBACK_PTR_NULL                                          "NYX_CALLBACK_DEVICE_PTR_ERR"
#define MSGID_NYX_ASYNC_CALLBACK_ERR                                         "NYX_ASYNC_CALLBACK_ERR"
#define MSGID_NYX_PTHREAD_CREATE_ERR                                         "NYX_PTHREAD_CREATE_ERR"
#define MSGID_NYX_CALLBACK_DEVICE_PTR_NULL                                   "NYX_CALLBACK_DEVICE_PTR_ERR"

/** errors in nyx-lib when trying to open/lookup a symbol in nyx-modules */
#define MSGID_NYX_MODULE_OPEN_ERR                                            "NYX_OPEN_ERR"
#define MSGID_NYX_MODULE_OPEN_SYM_ERR                                        "NYX_OPEN_SYM_ERR"
#define MSGID_NYX_MODULE_CLOSE_SYM_ERR                                       "NYX_CLOSE_SYM_ERR"
#define MSGID_NYX_MODULE_DECLARE_MAJOR_ERR                                   "NYX_DECLARE_MAJ_NUM_ERR"
#define MSGID_NYX_MODULE_DECLARE_MINOR_ERR                                   "NYX_DECLARE_MIN_NUM_ERR"
#define MSGID_NYX_MODULE_DLSYM_ERR                                           "NYX_DLSYM_LOOK_UP_ERR"
#define MSGID_NYX_MODULE_MAJOR_VERS_ERR                                      "NYX_MAJOR_VERS_ERR"

#endif // NYXLIB_MSG__LOG_H__

