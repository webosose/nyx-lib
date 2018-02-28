// Copyright (c) 2014-2018 LG Electronics, Inc.
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
 * @file nyx_error.c
 *
 * @brief nyx erorr implementation
 *
 *******************************************************************************
 */

#include <nyx/common/nyx_error.h>

typedef struct
{
	nyx_error_t error;
	const char *descr;
} nyx_error_description;

static nyx_error_description descriptions[] =
{
	{NYX_ERROR_NONE,                    "Operation successful"},
	{NYX_ERROR_INVALID_HANDLE,          "Invalid handle passed to an API function"},
	{NYX_ERROR_WRONG_DEVICE_TYPE,       "Operation not defined for the supplied device"},
	{NYX_ERROR_DEVICE_NOT_EXIST,        "Device does not exist"},
	{NYX_ERROR_TOO_MANY_OPENS,          "Reached maximum opens allowed on device"},
	{NYX_ERROR_OUT_OF_MEMORY,           "Out of memory"},
	{NYX_ERROR_DEVICE_UNAVAILABLE,      "Device not present OR Connection to device not available"},
	{NYX_ERROR_UNSUPPORTED_DEVICE_TYPE, "No support for this device type currently"},
	{NYX_ERROR_INVALID_VALUE,           "Value passed to an API function is not valid"},
	{NYX_ERROR_NOT_IMPLEMENTED,         "The API function has not been implemented by module"},
	{NYX_ERROR_INVALID_EVENT_TYPE,      "Event is of a wrong type for this operation"},
	{NYX_ERROR_INVALID_OPERATION,       "This operation cannot be performed at this time"},
	{NYX_ERROR_INVALID_FILE_ACCESS,     "The requested access to the file is not allowed"},
	{NYX_ERROR_VALUE_OUT_OF_RANGE,      "The resulting value was out of range"},
	{NYX_ERROR_NOT_FOUND,               "Could not find the requested value"},
	{NYX_ERROR_GENERIC,                 "Generic error"},
	{NYX_ERROR_ALREADY_UP_TO_DATE,      "Firmware is already up-to-date"},
	{NYX_ERROR_BAD_CHECKSUM,            "Bad checksum"},
	{NYX_ERROR_INCOMPATIBLE_LIBRARY,    "The nyx-lib being used is incompatible with the ABI the caller or module expects"},
};

const char *nyx_error_to_string(nyx_error_t error)
{
	if (error < 0 || error >= sizeof(descriptions) / sizeof(descriptions[0]))
	{
		return "Unknown error";
	}

	return descriptions[error].descr;
}
