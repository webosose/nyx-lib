// Copyright (c) 2022-2023 LG Electronics, Inc.
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

/**
 * @file nyx_cec_common.h
 *
 */

#ifndef _NYX_CEC_COMMON_H_
#define _NYX_CEC_COMMON_H_

#include <nyx/common/nyx_device.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NYX_CEC_PARAM_NAME_LEN 200
#define NYX_CEC_PARAM_VALUE_LEN 300
#define NYX_CEC_COMMAND_NAME_LEN 50
#define NYX_CEC_COMMAND_PARAMS_LEN 50
#define NYX_CEC_RESPONSE_COUNT 200
#define NYX_CEC_RESPONSE_LEN 200

typedef struct nyx_cec_data {
    char name[NYX_CEC_PARAM_NAME_LEN];
    char value[NYX_CEC_PARAM_VALUE_LEN];
} nyx_cec_data_t;

typedef struct nyx_cec_command {
    char name[NYX_CEC_COMMAND_NAME_LEN];
    int size;
    nyx_cec_data_t params[NYX_CEC_COMMAND_PARAMS_LEN];
} nyx_cec_command_t;

typedef struct nyx_cec_response {
    int size;
    char responses[NYX_CEC_RESPONSE_COUNT][NYX_CEC_RESPONSE_LEN];
} nyx_cec_response_t;

typedef void (* nyx_cec_response_callback)(nyx_cec_response_t *response);

typedef struct
{
	void                                   *user_data;
	nyx_cec_response_callback              response_cb;
} nyx_cec_callbacks_t;

#ifdef __cplusplus
}
#endif

#endif /* _NYX_CEC_COMMON_H_ */
