/*
 * sbdi_crypto.h
 *
 *  Created on: Jun 13, 2014
 *      Author: dhein
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SBDI_CRYPTO_H_
#define SBDI_CRYPTO_H_

#include "sbdi_config.h"
#include "sbdi_ctr_128b.h"

#include <stdint.h>

typedef uint8_t sbdi_key_t[32];

typedef sbdi_error_t (*sbdi_encrypt)(void *ctx, const uint8_t *pt,
    const int pt_len, const sbdi_ctr_128b_t *ctr, const uint32_t blk_nbr,
    uint8_t *ct, sbdi_tag_t tag);

typedef sbdi_error_t (*sbdi_decrypt)(void *ctx, const uint8_t *ct,
    const int ct_len, const sbdi_ctr_pkd_t ctr, const uint32_t blk_nbr,
    uint8_t *pt, const sbdi_tag_t tag);

typedef sbdi_error_t (*sbdi_mac)(void *ctx, const unsigned char *msg,
    const int mlen, unsigned char *C, const unsigned char *ad, const int ad_len);

typedef struct sbdi_crypto {
  void *ctx;
  sbdi_encrypt enc;
  sbdi_decrypt dec;
  sbdi_mac mac;
} sbdi_crypto_t;

#endif /* SBDI_CRYPTO_H_ */

#ifdef __cplusplus
}
#endif