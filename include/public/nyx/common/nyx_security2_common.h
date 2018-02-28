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

/**
 * @file nyx_security2_common.h
 *
 */


#ifndef _NYX_SECURITY2_COMMON_H_
#define _NYX_SECURITY2_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_security2_public Security
* @ingroup nyx_public
* @brief Nyx's public security2 API.
* @{
*/

/**
 * @brief RSA operations
 */
typedef enum
{
	NYX_SECURITY_RSA_DECRYPT,
	NYX_SECURITY_RSA_ENCRYPT,
	NYX_SECURITY_RSA_SIGN,
	NYX_SECURITY_RSA_VERIFY,
}
nyx_security_rsa_operation_t;


/**
 * @brief symmetric cipher block modes
 */
typedef enum
{
	NYX_SECURITY_MODE_CBC,
	NYX_SECURITY_MODE_ECB,
	NYX_SECURITY_MODE_CFB,
}
nyx_security_block_mode_t;
/**
 * @brief symmetric cipher block padding
 */
typedef enum
{
	NYX_SECURITY_PADDING_NONE,
	NYX_SECURITY_PADDING_PKCS5,
}
nyx_security_padding_t;

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_security2_COMMON_H_ */

