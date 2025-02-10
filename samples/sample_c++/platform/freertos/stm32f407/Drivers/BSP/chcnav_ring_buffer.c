/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file ring.c
 * @brief This is the header file for "hal_uart.c".
 ********************************************************************************/

#include "chcnav_ring_buffer.h"
#include <string.h>

#define RINGBUF_MIN(a, b) (((a)<(b))?(a):(b))

static uint16_t ring_buf_align_2(uint16_t buf_size)
{
    uint16_t i = 0;

    while ((1 << (++i)) <= buf_size);
    return (uint16_t) (1 << (--i));
}

void chcnav_ring_buf_init(RingBufferStruct *pthis, uint8_t *pbuf, uint16_t buf_size)
{
    pthis->read_index = 0;
    pthis->write_index = 0;
    pthis->buffer_ptr = pbuf;
    pthis->buffer_size = ring_buf_align_2(buf_size);
}

uint16_t chcnav_ring_buf_put(RingBufferStruct *pthis, const uint8_t *pdata, uint16_t data_len)
{
    uint16_t write_len;

    data_len = RINGBUF_MIN(data_len, (uint16_t) (pthis->buffer_size - pthis->write_index + pthis->read_index));

    //fill up data
    write_len = RINGBUF_MIN(data_len, (uint16_t) (pthis->buffer_size - (pthis->write_index & (pthis->buffer_size - 1))));
    memcpy(pthis->buffer_ptr + (pthis->write_index & (pthis->buffer_size - 1)), pdata, write_len);

    //fill begin data
    memcpy(pthis->buffer_ptr, pdata + write_len, data_len - write_len);

    pthis->write_index += data_len;

    return data_len;
}

uint16_t chcnav_ring_buf_get(RingBufferStruct *pthis, uint8_t *pdata, uint16_t data_len)
{
    uint16_t read_len;

    data_len = RINGBUF_MIN(data_len, (uint16_t) (pthis->write_index - pthis->read_index));

    //get up data
    read_len = RINGBUF_MIN(data_len, (uint16_t) (pthis->buffer_size - (pthis->read_index & (pthis->buffer_size - 1))));
    memcpy(pdata, pthis->buffer_ptr + (pthis->read_index & (pthis->buffer_size - 1)), read_len);

    //get begin data
    memcpy(pdata + read_len, pthis->buffer_ptr, data_len - read_len);

    pthis->read_index += data_len;

    return data_len;
}

uint16_t chcnav_ring_uf_get_nused_size(RingBufferStruct *pthis)
{
    return (uint16_t) (pthis->buffer_size - pthis->write_index + pthis->read_index);
}
