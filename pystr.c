#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct String
{
    char content[MAX];
    unsigned long length;
} String;

void upper(String *s)
{
    char temp[s->length];

    strcpy(temp, (const char *) s->content);
    for (int i = 0; i < s->length; ++i)
    {
        if (temp[i] >= 'a' && temp[i] <= 'z')
        {
            temp[i] = temp[i] - 32;
        }
    }
    strcpy(s->content, temp);
}

void lower(String *s)
{
    char temp[s->length];

    strcpy(temp, (const char *) s->content);
    for (int i = 0; i < s->length; ++i)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
        {
            temp[i] = temp[i] + 32;
        }
    }
    strcpy(s->content, temp);
}

String *string_builder(char *s)
{
    String *temp = malloc(sizeof(String));
    strcpy(temp->content, s);
    temp->length = strlen(s);
    return temp;
}

String *copy(String *string)
{
    return string_builder(string->content);
};

void set_content(String *str, char *s)
{
    strcpy(str->content, s);
    str->length = strlen(s);
}

void destroy(String *s)
{
    free(s);
}
