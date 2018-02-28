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

/********************************************************************************
 * @file nyx_security2_impl.c
 *
 * @brief This is the nyx security2 lib implementation
 ********************************************************************************/

#include "nyx_device_impl.h"
#include <nyx/module/nyx_device_internal.h>
#include <nyx/client/nyx_security2.h>

nyx_error_t nyx_security2_create_aes_key(nyx_device_handle_t handle,
        int keybits,
        unsigned char *keydata)
{
	nyx_execute_return_function(security2_create_aes_key, SECURITY2, CREATE_AES_KEY,
	                            handle, keybits, keydata);
}

nyx_error_t nyx_security2_crypt_aes(nyx_device_handle_t handle,
                                    const unsigned char *keydata, int keybits,
                                    nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
                                    int srclen,
                                    unsigned char *dest, int *destlen, const unsigned char *iv, int ivlen,
                                    nyx_security_padding_t padding, unsigned char *nextIv, int nextIvLen)
{
	nyx_execute_return_function(security2_crypt_aes, SECURITY2, CRYPT_AES, handle,
	                            keydata, keybits, mode, encrypt, src, srclen, dest, destlen, iv, ivlen,
	                            padding, nextIv, nextIvLen);
}

nyx_error_t nyx_security2_crypt_aes_simple(nyx_device_handle_t handle,
        const unsigned char *keydata, int keybits,
        nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
        int srclen,
        unsigned char *dest, int *destlen)
{
	nyx_execute_return_function(security2_crypt_aes_simple, SECURITY2,
	                            CRYPT_AES_SIMPLE, handle,
	                            keydata, keybits, mode, encrypt, src, srclen, dest, destlen);
}


nyx_error_t nyx_security2_create_rsa_key(nyx_device_handle_t handle,
        int keybits,
        unsigned char *keydata, int *serializedKeyDataLen,
        unsigned char *publicKey, int *pubKeySize)
{
	nyx_execute_return_function(security2_create_rsa_key, SECURITY2, CREATE_RSA_KEY,
	                            handle, keybits, keydata, serializedKeyDataLen,
	                            publicKey, pubKeySize);
}

nyx_error_t nyx_security2_crypt_rsa(nyx_device_handle_t handle,
                                    const unsigned char *keydata,
                                    int serializedKeyDataLen, nyx_security_rsa_operation_t operation,
                                    const unsigned char *src, int srclen,
                                    unsigned char *dest, int *destlen)
{
	nyx_execute_return_function(security2_crypt_rsa, SECURITY2, CRYPT_RSA, handle,
	                            keydata, serializedKeyDataLen, operation, src, srclen, dest, destlen);
}

nyx_error_t nyx_security2_create_des3_key(nyx_device_handle_t handle,
        int keybits,
        unsigned char *keydata)
{
	nyx_execute_return_function(security2_create_des3_key, SECURITY2,
	                            CREATE_3DES_KEY,
	                            handle, keybits, keydata);
}

nyx_error_t nyx_security2_crypt_des3(nyx_device_handle_t handle,
                                     const unsigned char *keydata,
                                     nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
                                     int srclen,
                                     unsigned char *dest, int *destlen, const unsigned char *iv, int ivlen,
                                     nyx_security_padding_t padding, unsigned char *nextIv, int nextIvLen)
{
	nyx_execute_return_function(security2_crypt_des3, SECURITY2, CRYPT_3DES, handle,
	                            keydata, mode, encrypt, src, srclen, dest, destlen, iv, ivlen, padding, nextIv,
	                            nextIvLen);
}

nyx_error_t nyx_security2_crypt_des3_simple(nyx_device_handle_t handle,
        const unsigned char *keydata,
        nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
        int srclen,
        unsigned char *dest, int *destlen)
{
	nyx_execute_return_function(security2_crypt_des3_simple, SECURITY2,
	                            CRYPT_3DES_SIMPLE, handle,
	                            keydata, mode, encrypt, src, srclen, dest, destlen);
}


nyx_error_t nyx_security2_create_hmac_key(nyx_device_handle_t handle,
        int keybits,
        unsigned char *keydata)
{
	nyx_execute_return_function(security2_create_hmac_key, SECURITY2,
	                            CREATE_HMAC_KEY,
	                            handle, keybits, keydata);
}

nyx_error_t nyx_security2_hmac(nyx_device_handle_t handle,
                               const unsigned char *keydata, int keybits,
                               const unsigned char *src, int srclen,
                               unsigned char *dest, int *destlen)
{
	nyx_execute_return_function(security2_hmac, SECURITY2, HMAC, handle,
	                            keydata, keybits, src, srclen, dest, destlen);
}
