#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct String
{
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

void destroy(String *s)
{
    free(s);
}
