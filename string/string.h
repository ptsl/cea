
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

/*
 * String - a simple wrapper around char array.
 *
 * Every string instance keeps its length and its own internal copy
 * of data.
 */
#ifndef STRING_H
#define STRING_H

/*
 * An opaque data type.
 */
struct string;
typedef struct string string;

/*
 * Constructor.
 *
 * Allocates new memory and copies the data. Returns a pointer.
 *
 * NULL argument is not allowed, an empty string ("") is.
 */
string *string_new(const char *str);

/*
 * Destructor. Frees the memory up.
 */
void string_del(string *s);

/*
 * Returns a pointer to the internal data. The data is returned as
 * const char *, that is, it is not modifiable.
 *
 * The function name is deliberately short, as it's supposed to be used
 * in arguments of other functions, such as 'printf("%s\n", str(s))'.
 */
const char *str(const string *s);

/*
 * Creates a copy of the existing string by allocating new memory and
 * copying characters from the source. The allocated memory should be freed
 * with string_del. The string is copied in its whole length, not only until
 * the first '\0'.
 */
string *string_clone(const string *other);

/*
 * Returns a single character. Checks for index boundaries, unless
 * NDEBUG is defined.
 */
char string_getc(const string *s, size_t i);

/*
 * Returns true if string's length is zero. A NULL pointer is rejected
 * (it's neither empty, nor non-empty).
 */
bool string_isempty(const string *s);

/*
 * Returns the number of ASCII characters in the string (without
 * the terminating null character).
 */
size_t string_len(const string *s);

/*
 * Modifies a single character. Checks for index boundaries,
 * unless NDEBUG is defined.
 */
void string_setc(string *s, size_t i, char c);

#endif
