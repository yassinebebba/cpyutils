#include <string.h>
#include <stdio.h>

typedef struct String
{
    unsigned long length;
    char content[];
} String;

String *string_builder(char *);

String *copy(String *);

void slice(String *, u_long, u_long);

void upper(String *);

void lower(String *);

void set_content(String *, char *);

void title(String *string);

void squeeze(String *, char);

void repeat(String *, unsigned long);

void append(String *, const char *);
