#include <string.h>

#define MAX 1000
typedef struct String
{
    char content[MAX];
    unsigned long length;
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
