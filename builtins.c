#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "pystr.h"
#include "pyint.h"


#define GenericType(x) _Generic((x), \
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
int *: TYPENAME_INT_POINTER,  \
String *: TYPENAME_INT_POINTER, \
default: TYPENAME_OTHER)

typedef enum type_name
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
    TYPENAME_STRING_POINTER,
    TYPENAME_INTEGER_POINTER,
    TYPENAME_OTHER,
} type_name;

typedef struct pyobject
{
    type_name type;
    String *string;
} pyobject;

void private_print(char *format, ...)
{
    va_list args;
    va_start(args, format);
    for (unsigned int i = 0; i < 2; ++i)
    {
        int *obj = va_arg(args, int *);
        switch (*obj)
        {
            case TYPENAME_STRING_POINTER:
                printf("%s", get_content((String *) obj));
                break;
            case TYPENAME_INTEGER_POINTER:
                printf("%lu", get_integer((Integer *) obj));
                 break;
            case TYPENAME_BOOL:
                break;
            case TYPENAME_UNSIGNED_CHAR:
                break;
            case TYPENAME_CHAR:
                break;
            case TYPENAME_SIGNED_CHAR:
                break;
            case TYPENAME_SHORT_INT:
                break;
            case TYPENAME_UNSIGNED_SHORT_INT:
                break;
            case TYPENAME_INT:
                break;
            case TYPENAME_UNSIGNED_INT:
                break;
            case TYPENAME_LONG_INT:
                break;
            case TYPENAME_UNSIGNED_LONG_INT:
                break;
            case TYPENAME_LONG_LONG_INT:
                break;
            case TYPENAME_UNSIGNED_LONG_LONG_INT:
                break;
            case TYPENAME_FLOAT:
                break;
            case TYPENAME_DOUBLE:
                break;
            case TYPENAME_LONG_DOUBLE:
                break;
            case TYPENAME_CHAR_POINTER:
                break;
            case TYPENAME_VOID_POINTER:
                break;
            case TYPENAME_INT_POINTER:
                break;
            case TYPENAME_OTHER:
                break;
        }
    }
    va_end(args);
}