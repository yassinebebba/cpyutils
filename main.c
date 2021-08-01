#include <stdio.h>
#include "pystr.h"

int main()
{
    String *str = string_builder("I love Shaira");
    printf("%s\n", str->content);

    // clean heap
    destroy(str);
    return 0;
}
