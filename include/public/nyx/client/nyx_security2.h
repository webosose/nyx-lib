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
 * @file nyx_security2.h
 *
 */

/**
 * @brief Nyx's public API for accessing security2 module
 *
 */

#ifndef _NYX_SECURITY2_H_
#define _NYX_SECURITY2_H_

#include <nyx/common/nyx_device.h>
#include <nyx/common/nyx_security2_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nyx_security2_public Security
 * @ingroup nyx_public
 * @{
 */

/**
 * @defgroup nyx_security2_aes AES
 * @ingroup nyx_security2_public
 * @{
 */

/**
 * @brief Create AES key
 *
 * @param[in] handle - handle to the device
 * @param[in] keybits - key length in bits (128, 256, ...)
 * @param[in,out] keydata - generated key data
 *                in: pointer to contain key
 *                out: generated key data
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_create_aes_key(nyx_device_handle_t handle, int keybits,
                             unsigned char *keydata);

/**
 * @brief Encrypt/decrypt data
 *
 * @param[in] handle - handle to the device
 * @param[in] encrypt - encrypt != 0, decrypt = 0
 * @param[in] keydata - key data
 * @param[in] keybits - key length in bits (128, 256, ...)
 * @param[in] mode - block cipher mode
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer (includes IV in decrypt)
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data
 * @param[in] iv - init vector
 * @param[in] ivlen - length of IV
 * @param[in] padding - padding (NONE, PKCS5)
 * @param[out] nextIv - next init vector
 * @param[in] nextIvLen - nex IV length
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_crypt_aes(nyx_device_handle_t handle,
                        const unsigned char *keydata, int keybits,
                        nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
                        int srclen,
                        unsigned char *dest, int *destlen, const unsigned char *iv, int ivlen,
                        nyx_security_padding_t padding, unsigned char *nextIv, int nextIvLen);

/**
 * @brief Encrypt/decrypt data
 *
 * Encryption generates IV and returns it at front of dest buffer.
 * Decryption requires that IV is at front of src buffer.
 * Destination buffer size need to have space for encrypted data + IV + block size of used cipher.
 *
 * @param[in] handle - handle to the device
 * @param[in] encrypt - encrypt != 0, decrypt = 0
 * @param[in] keydata - key data
 * @param[in] keybits - key length in bits (128, 256, ...)
 * @param[in] mode - block cipher mode (CBC, ECB, CFB, ...)
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer (includes IV in decrypt)
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */


NYX_API_EXPORT nyx_error_t
nyx_security2_crypt_aes_simple(nyx_device_handle_t handle,
                               const unsigned char *keydata, int keybits,
                               nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
                               int srclen,
                               unsigned char *dest, int *destlen);

/** @} */

/**
 * @defgroup nyx_security2_rsa RSA
 * @ingroup nyx_security2_public
 * @{
 */

/**
 * @brief Create RSA key
 *
 * Called with NULL buffers to estimate private and public keys sizes
 * @param[in] handle - handle to the device
 * @param[in] keybits - length of RSA key in bits (1024, 2048, 4096, ...)
 * @param[in,out] keydata - generated keydata
 *                in: pointer to contain key
 *                out: generated key data
 * @param[in, out] serializedKeyDataLen - size of keydata
 *                in: pointer to contain size
 *                out: size of keydata
* @param[in,out] publicKey - generated public keydata
 *                in: pointer to contain key
 *                out: generated key data
 * @param[in, out] pubKeySize - size of public keydata
 *                in: pointer to contain size
 *                out: size of keydata
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_create_rsa_key(nyx_device_handle_t handle, int keybits,
                             unsigned char *keydata, int *serializedKeyDataLen,
                             unsigned char *publicKey, int *pubKeySize);

/**
 * @brief Encrypt/decrypt data
 *
 * @param[in] handle - handle to the device
 * @param[in] operation - encrypt, decrypt, sign, verify
 * @param[in] keydata - rsa key data
 * @param[in] keybits - key length in bits (2048)
 * @param[in] serializedKeyDataLen - keydata length
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer
 * @param[in, out] dest - crypted data
 * @param[out] destlen - length of crypted data
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_crypt_rsa(nyx_device_handle_t handle,
                        const unsigned char *keydata, int serializedKeyDataLen,
                        nyx_security_rsa_operation_t operation, const unsigned char *src, int srclen,
                        unsigned char *dest, int *destlen);
/**
 * @brief Create 3 DES key
 *
 * @param[in] handle - handle to the device
 * @param[in] keybits - key length in bits (192)
 * @param[in,out] keydata - generated key data
 *                in: pointer to contain key
 *                out: generated key data
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_create_des3_key(nyx_device_handle_t handle, int keybits,
                              unsigned char *keydata);

/**
 * @brief Encrypt/decrypt data
 *
 * @param[in] handle - handle to the device
 * @param[in] encrypt - encrypt != 0, decrypt = 0
 * @param[in] keydata - key data
 * @param[in] mode - block cipher mode (CBC, ECB, CFB, ...)
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer (includes IV in decrypt)
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data (includes IV in encrypt)
 * @param[in] iv - init vector
 * @param[in] ivlen - length of IV
 * @param[in] padding - padding
 * @param[out] nextIv - next init vector
 * @param[in] nextIvLen - nex IV length
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_crypt_des3(nyx_device_handle_t handle,
                         const unsigned char *keydata,
                         nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
                         int srclen,
                         unsigned char *dest, int *destlen, const unsigned char *iv, int ivlen,
                         nyx_security_padding_t padding, unsigned char *nextIv, int nextIvLen);

/**
 * @brief Encrypt/decrypt data
 *
 * Encryption generates IV and returns it at front of dest buffer.
 * Decryption requires that IV is at front of src buffer.
 * Destination buffer size need to have space for encrypted data + IV + block size of used cipher.
 *
 * @param[in] handle - handle to the device
 * @param[in] encrypt - encrypt != 0, decrypt = 0
 * @param[in] keydata - key data
 * @param[in] mode - block cipher mode
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer (includes IV in decrypt)
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data (includes IV in encrypt)
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_crypt_des3_simple(nyx_device_handle_t handle,
                                const unsigned char *keydata,
                                nyx_security_block_mode_t mode, int encrypt, const unsigned char *src,
                                int srclen,
                                unsigned char *dest, int *destlen);

/**
 * @brief Create HMAC SHA key
 *
 * @param[in] handle - handle to the device
 * @param[in] keybits - key length in bits (192)
 * @param[in,out] keydata - generated key data
 *                in: pointer to contain key
 *                out: generated key data
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_create_hmac_key(nyx_device_handle_t handle, int keybits,
                              unsigned char *keydata);

/**
 * @brief hmac data
 *
 * @param[in] handle - handle to the device
 * @param[in] keydata - key data
 * @param[in] keybits - key length in bits
 * @param[in] src - buffer to crypt
 * @param[in] srclen - length of src buffer (includes IV in decrypt)
 * @param[in] dest - crypted data
 * @param[out] destlen - length of crypted data (includes IV in encrypt)
 *
 * @return error code
 *   - NYX_ERROR_NONE if operation is successful
 */
NYX_API_EXPORT nyx_error_t
nyx_security2_hmac(nyx_device_handle_t handle,
                   const unsigned char *keydata, int keybits,
                   const unsigned char *src, int srclen,
                   unsigned char *dest, int *destlen);
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _NYX_SECURITY2_H_ */
