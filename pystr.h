#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define print(s) printf("%s", get_content(s))
#define len(s) get_length(s)

typedef struct str String;

unsigned long get_length(String *s);

char *get_content(String *s);

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
