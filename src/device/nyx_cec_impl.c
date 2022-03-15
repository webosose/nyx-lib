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
 *******************************************************************************
 * @file nyx_cec_impl.c
 *
 * @brief Implementation of NYX's public API for accessing Cec
 *
 *******************************************************************************
 */

#include <stdio.h>
#include <inttypes.h>
#include "nyx_cec_impl.h"

nyx_error_t nyx_cec_set_callback(nyx_device_handle_t handle,
                                           nyx_cec_callbacks_t *cec_cbs)
{
	nyx_execute_return_function(cec_set_callback, CEC, SET_CALLBACK, handle, cec_cbs);
}

nyx_error_t nyx_cec_send_command(nyx_device_handle_t handle, nyx_cec_command_t *command)
{
	nyx_execute_return_function(cec_send_command, CEC, SEND_COMMAND, handle, command);
}

nyx_error_t nyx_cec_get_physical_address(nyx_device_handle_t handle, char **address)
{
	nyx_execute_return_function(cec_get_physical_address, CEC, GET_PHYSICAL_ADDRESS, handle, address);
}

nyx_error_t nyx_cec_set_config(nyx_device_handle_t handle, char *type, char *value)
{
	nyx_execute_return_function(cec_set_config, CEC, SET_CONFIG, handle, type, value);
}

nyx_error_t nyx_cec_get_config(nyx_device_handle_t handle, char *type, char **value)
{
	nyx_execute_return_function(cec_get_config, CEC, GET_CONFIG, handle, type, value);
}

nyx_error_t nyx_cec_get_version(nyx_device_handle_t handle, char **version)
{
	nyx_execute_return_function(cec_get_version, CEC, GET_VERSION, handle, version);
}
