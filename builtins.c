#include <stdio.h>
#include <stdarg.h>
#include "pystr.h"


#define Type(x) _Generic((x), \
_Bool: TYPENAME_BOOL, \
unsigned char: TYPENAME_UNSIGNED_CHAR, \
char: TYPENAME_CHAR, \
signed char: TYPENAME_SIGNED_CHAR, \
short int: TYPENAME_SHORT_INT, \
unsigned short int: TYPENAME_UNSIGNED_SHORT_INT, \
int: TYPENAME_INT, \
unsigned int: TYPENAME_UNSIGNED_INT, \
long int: TYPENAME_LONG_INT, \
unsigned long int: TYPENAME_UNSIGNED_LONG_INT, \
long long int: TYPENAME_LONG_LONG_INT, \
unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT, \
float: TYPENAME_FLOAT, \
double: TYPENAME_DOUBLE, \
long double: TYPENAME_LONG_DOUBLE, \
char *: TYPENAME_CHAR_POINTER, \
void *: TYPENAME_VOID_POINTER, \
int *: TYPENAME_INT_POINTER, \
default: TYPENAME_OTHER)

enum type_name
{
    TYPENAME_BOOL,
    TYPENAME_UNSIGNED_CHAR,
    TYPENAME_CHAR,
    TYPENAME_SIGNED_CHAR,
    TYPENAME_SHORT_INT,
    TYPENAME_UNSIGNED_SHORT_INT,
    TYPENAME_INT,
    TYPENAME_UNSIGNED_INT,
    TYPENAME_LONG_INT,
    TYPENAME_UNSIGNED_LONG_INT,
    TYPENAME_LONG_LONG_INT,
    TYPENAME_UNSIGNED_LONG_LONG_INT,
    TYPENAME_FLOAT,
    TYPENAME_DOUBLE,
    TYPENAME_LONG_DOUBLE,
    TYPENAME_CHAR_POINTER,
    TYPENAME_VOID_POINTER,
    TYPENAME_INT_POINTER,
    TYPENAME_OTHER
};


void print(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (unsigned int i = 0; i < count; ++i)
    {
        void *obj = va_arg(args, void *);
        switch (Type(obj))
        {

        }
        printf("%s", get_content((String *) obj));
//        switch (Type(obj))
//        {
//            case expression:
//        }
//        printf("%s", get_content(va_arg(args, String *)));
    }
    va_end(args);
}