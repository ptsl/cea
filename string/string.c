
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

#include "globals.h"
#include "string.h"

struct string {
    size_t len;
    char str[1];  /* Struct hack. '1' for the terminating '\0' */
};

string *string_new(const char *str)
{
    register const char *s;
    register char *t;
    register size_t len = 0;
    struct string *ret;

    assert(str);

    s = str;
    while (*s++)
        len++;

    /* '\0' is already taken care of in struct's definition */
    ret = malloc(sizeof(struct string) + len);
    if (!ret)
        fatal(E_OUT_OF_MEMORY);

    ret->len = len;

    s = str;
    t = ret->str;
    while ((*t++ = *s++)) ;  /* string copy */

    return ret;
}

void string_del(string *s)
{
    assert(s);

    free(s);
}

const char *str(const string *s)
{
    assert(s);

    return s->str;
}

string *string_clone(const string *other)
{
    register size_t i;
    struct string *ret;

    assert(other);

    /* '\0' is already taken care of in struct's definition */
    ret = (struct string *) malloc(sizeof(struct string) + other->len);
    if (!ret)
        fatal(E_OUT_OF_MEMORY);

    ret->len = other->len;

    for (i = 0; i < other->len; i++)
        ret->str[i] = other->str[i];

    ret->str[ret->len] = '\0';

    return ret;
}

char string_getc(const string *s, size_t i)
{
    assert(s);
    assert(i < s->len);

    return s->str[i];
}

bool string_isempty(const string *s)
{
    assert(s);

    return s->len == 0;
}

size_t string_len(const string *s)
{
    assert(s);

    return s->len;
}

void string_setc(string *s, size_t i, char c)
{
    assert(s);
    assert(i < s->len);

    s->str[i] = c;
}
