
/******************************************************************************
 *                                                                            *
 *    The MIT License (MIT)                                                   *
 *                                                                            *
 *    Copyright (c) 2013 Peter Slížik                                         *
 *                                                                            *
 *    Permission  is  hereby  granted,  free  of  charge,  to  any  person    *
 *    obtaining a copy of this software and associated documentation files    *
 *    (the  "Software"),  to deal  in  the  Software without  restriction,    *
 *    including without limitation the rights to use, copy, modify, merge,    *
 *    publish, distribute, sublicense, and/or sell copies of the Software,    *
 *    and to  permit persons to whom  the Software is furnished  to do so,    *
 *    subject to the following conditions:                                    *
 *                                                                            *
 *    The  above copyright  notice  and this  permission  notice shall  be    *
 *    included in all copies or substantial portions of the Software.         *
 *                                                                            *
 *    THE  SOFTWARE  IS   PROVIDED  "AS  IS",  WITHOUT   WARRANTY  OF  ANY    *
 *    KIND,  EXPRESS  OR  IMPLIED,  INCLUDING   BUT  NOT  LIMITED  TO  THE    *
 *    WARRANTIES OF MERCHANTABILITY, FITNESS  FOR A PARTICULAR PURPOSE AND    *
 *    NONINFRINGEMENT. IN NO EVENT SHALL  THE AUTHORS OR COPYRIGHT HOLDERS    *
 *    BE LIABLE FOR  ANY CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN    *
 *    ACTION OF  CONTRACT, TORT OR OTHERWISE,  ARISING FROM, OUT OF  OR IN    *
 *    CONNECTION WITH  THE SOFTWARE OR  THE USE  OR OTHER DEALINGS  IN THE    *
 *    SOFTWARE.                                                               *
 *                                                                            *
 ******************************************************************************/

#include <stdlib.h>
#include "globals.h"
#include "buffer.h"
#include <stdio.h>

static inline void _ensure_space(buffer *buf, size_t requested) {}
/*
 * http://stackoverflow.com/questions/5446698/map-anonymous-with-c99-standard
 */

buffer *buffer_new(void)
{
    struct buffer *ret;

    // Memory allocation starts at 16 bytes.
    // GNU malloc always returns at least 16 bytes on 64-bit machines.
    ret = malloc(sizeof(struct buffer) + 16);
    if (!ret)
        fatal(E_OUT_OF_MEMORY);

    ret->alloc = 16;
    ret->size = 0;
    // We don't have to care about ret->data now.

    return ret;
}

extern inline void buffer_del(buffer *buf);

void buffer_putc(buffer *buf, char c)
{
    assert(buf);

    _ensure_space(buf, buf->size + 1);  // Make room for the new char

    buf->data[buf->size] = c;
    buf->size++;
}

extern inline size_t buffer_size(const buffer *buf);

void bufprint(const buffer *buf)
{
    for (size_t i = 0; i < buf->size; i++) {
        putchar(buf->data[i]);
    }

    putchar('\n');
    printf("alloc: %zu, size: %zu\n", buf->alloc, buf->size);
}
// TODO: remove stdio
