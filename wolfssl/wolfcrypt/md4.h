/* md4.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

/*!
    \file wolfssl/wolfcrypt/md4.h
*/

#ifndef WOLF_CRYPT_MD4_H
#define WOLF_CRYPT_MD4_H

#include <wolfssl/wolfcrypt/types.h>

#ifndef NO_MD4

#ifdef __cplusplus
    extern "C" {
#endif

/* in bytes */
enum {
    WC_MD4_BLOCK_SIZE  = 64,
    WC_MD4_DIGEST_SIZE = 16,
    WC_MD4_PAD_SIZE    = 56
};

/* MD4 digest */
typedef struct wc_Md4 {
    word32  buffLen;   /* in bytes          */
    word32  loLen;     /* length in bytes   */
    word32  hiLen;     /* length in bytes   */
    word32  digest[WC_MD4_DIGEST_SIZE / sizeof(word32)];
    word32  buffer[WC_MD4_BLOCK_SIZE  / sizeof(word32)];
} wc_Md4;

WOLFSSL_API void wc_InitMd4(wc_Md4* md4);
WOLFSSL_API void wc_Md4Update(wc_Md4* md4, const byte* data, word32 len);
WOLFSSL_API void wc_Md4Final(wc_Md4* md4, byte* hash);

#ifndef OPENSSL_COEXIST

enum {
    MD4             = WC_HASH_TYPE_MD4,
    MD4_BLOCK_SIZE  = WC_MD4_BLOCK_SIZE,
    MD4_DIGEST_SIZE = WC_MD4_DIGEST_SIZE,
    MD4_PAD_SIZE    = WC_MD4_PAD_SIZE
};

typedef struct wc_Md4 Md4;

#endif /* !OPENSSL_COEXIST */


#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* NO_MD4 */
#endif /* WOLF_CRYPT_MD4_H */

