
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
#include <stdio.h>
#include "list.h"

/*
 * Creates a new empty list.
 */
list *list_new()
{
    return NULL;
}

/*
 * Creates a new list with one element.
 *
 * Calls exit() if the system is out of memory.
 */
list *list_new1(void *elem)
{
    struct list *l;

    l = malloc(sizeof(struct list));
    if (!l) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    l->data = elem;
    l->next = NULL;

    return l;
}

/*
 * Prints the list.
 */
void list_print(list *l)
{
    struct list *iter = l;

    printf("(");
    while (iter) {
        printf("%d", *(int*)(iter->data));
        if (iter->next)
            printf(" ");
        iter = iter->next;
    }
    printf(")");
}
