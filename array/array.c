
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

#include <assert.h>
#include <stdlib.h>
#include "array.h"

struct array {
    size_t len;
    void *arr[1];  /* Struct hack */
};

array *array_new(size_t size)
{
    struct array *ret;

    assert(size > 0);

    /* TODO: calloc je rychlejsi, ale alokuje asi iba pole. */
    ret = malloc(sizeof(struct array) + (sizeof(void*) * (len - 1)));
    if (!ret)
        return NULL;

    ret->len = len;
}

void array_del(array *a)
{
}
