/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file ringbuffer.h
 * @brief This is the header file for "ringbuffer.h",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

typedef struct {
    uint8_t *buffer_ptr;
    uint16_t buffer_size;

    uint16_t read_index;
    uint16_t write_index;
} RingBufferStruct;

void chcnav_ring_buf_init(RingBufferStruct *pthis, uint8_t *pbuf, uint16_t buf_size);
uint16_t chcnav_ring_buf_put(RingBufferStruct *pthis, const uint8_t *pdata, uint16_t data_len);
uint16_t chcnav_ring_buf_get(RingBufferStruct *pthis, uint8_t *pdata, uint16_t data_len);
uint16_t chcnav_ring_uf_get_nused_size(RingBufferStruct *pthis);

#endif
