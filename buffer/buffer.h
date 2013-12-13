
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

#ifndef BUFFER_H
#define BUFFER_H

struct buffer {
    size_t alloc;  // Allocated memory in bytes
    size_t size;   // Actual data size in bytes
    char data[];   // Flexible array member
};

typedef struct buffer buffer;

/*
 * Constructor.
 * Allocates new memory and returns a pointer to it.
 * Calls fatal() in an out-of-memory condition.
 */
buffer *buffer_new(void)
    __attribute__((malloc));

/*
 * Destructor. Frees the memory up.
 */
inline void buffer_del(buffer *buf)
{
    free(buf);
}

/*
 * Appends a single character to the buffer.
 */
void buffer_putc(buffer *buf, char c)
    __attribute__((nonnull));

/*
 * Returns the object's size in bytes.
 */
inline size_t buffer_size(const buffer *buf)
{
    return buf->size;
}

void bufprint(const buffer *buf)
    __attribute__((nonnull));

#endif
