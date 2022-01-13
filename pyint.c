#include <stdint.h>
#include <stdlib.h>
#include "builtins.h"

typedef struct pyint
{
    type_name type;
    int64_t number;
} pyint;

pyint * integer_builder(int64_t value)
{
    pyint  * integer = malloc(sizeof(pyint));
    integer->type = TYPENAME_INTEGER_POINTER;
    integer->number = value;
    return integer;
}

int64_t get_integer(pyint * integer)
{
    return integer->number;
}