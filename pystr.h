#include <string.h>
#include <stdio.h>

typedef struct String
{
    unsigned long length;
    char content[];
} String;

String *string_builder(char *);

String *copy(String *);

void upper(String *);

void lower(String *);

void destroy(String *);

void set_content(String *, char *);

void title(String *string);

void squeeze(String *, char);

void repeat(String *, unsigned long);
