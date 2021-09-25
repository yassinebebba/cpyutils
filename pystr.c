#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct String
{
    // has to have a size field
    unsigned long length;
    char content[];
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
    String *temp = malloc(sizeof(String) + strlen(s) - 1);
    strcpy(temp->content, s);
    temp->length = strlen(s);
    return temp;
}

String *copy(String *string)
{
    String *temp = malloc(sizeof(String) + string->length - 1);
    strcpy(temp->content, string->content);
    temp->length = string->length;
    return temp;
}

void set_content(String *str, char *s)
{
    // TODO: if len < str->length >>> reduce the size
    unsigned long len = strlen(s);
    if (len > str->length)
    {
        str = realloc(str, sizeof(String) + strlen(s) - 1);
    }
    str->length = len;
    strcpy(str->content, s);
}

void title(String *string)
{
    for (int i = 0; i < string->length; ++i)
        if ((string->content[i - 1] == ' ' || string->content[i - 1] == '\t') && string->content[i] >= 'a' &&
            string->content[i] <= 'z')
            string->content[i] = string->content[i] - 32;
}

void squeeze(String *string, char c)
{
    // removes all occurrences a character

    int i, j;
    for (i = j = 0; i < string->length; ++i)
    {
        if (string->content[i] != c)
        {
            string->content[j++] = string->content[i];
        }
    }
    string->content[j] = '\0';
}

void repeat(String *string, const unsigned long c)
{
    char temp[1000];
    strcpy(temp, string->content);
    for (unsigned long i = 0; i < c * string->length; ++i)
    {
        string->content[i] = temp[i % string->length];
    }
    string->length = c * string->length;
}

void append(String *string, const char *s)
{
    // has to check if there is enough space
    unsigned long len = strlen(s);
    string = realloc(string, sizeof(String) + string->length + len - 1);
    strcpy(string->content + string->length, s);
    string->length += len;
}

void destroy(String *s)
{
    free(s);
}
