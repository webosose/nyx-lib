// Copyright (c) 2022 LG Electronics, Inc.
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
 * @file nyx_cec.h
 *
 */

/**
 * @brief Nyx's public API for accessing cec.
 *
 */

#ifndef _NYX_CEC_H_
#define _NYX_CEC_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_cec_common.h>

#ifdef __cplusplus
extern "C" {
#endif

NYX_API_EXPORT nyx_error_t nyx_cec_set_callback(nyx_device_handle_t handle, nyx_cec_callbacks_t *callbacks);

NYX_API_EXPORT nyx_error_t nyx_cec_send_command(nyx_device_handle_t handle, nyx_cec_command_t *command);

NYX_API_EXPORT nyx_error_t nyx_cec_get_physical_address(nyx_device_handle_t handle, char **address);

NYX_API_EXPORT nyx_error_t nyx_cec_set_config(nyx_device_handle_t handle, char *type, char *value);

NYX_API_EXPORT nyx_error_t nyx_cec_get_config(nyx_device_handle_t handle, char *type, char **value);

NYX_API_EXPORT nyx_error_t nyx_cec_get_version(nyx_device_handle_t handle, char **version);

#ifdef __cplusplus
}
#endif

#endif /* _NYX_CEC_H_ */
