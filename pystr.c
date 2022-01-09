#include <string.h>
#include <stdlib.h>


typedef struct str
{
    // has to have a size field
    unsigned long length;
    char content[];
} str;

void upper(str *s)
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

void lower(str *s)
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

str *string_builder(char *s)
{
    str *temp = malloc(sizeof(str) + strlen(s) - 1);
    strcpy(temp->content, s);
    temp->length = strlen(s);
    return temp;
}

str *copy(str *string)
{
    str *temp = malloc(sizeof(str) + string->length - 1);
    strcpy(temp->content, string->content);
    temp->length = string->length;
    return temp;
}

void set_content(str *string, char *s)
{
    // TODO: if len < str->length >>> reduce the size
    unsigned long len = strlen(s);
    if (len > string->length)
    {
        string = realloc(string, sizeof(str) + strlen(s) - 1);
    }
    string->length = len;
    strcpy(string->content, s);
}

void title(str *string)
{
    for (int i = 0; i < string->length; ++i)
        if ((string->content[i - 1] == ' ' || string->content[i - 1] == '\t') && string->content[i] >= 'a' &&
            string->content[i] <= 'z')
            string->content[i] = string->content[i] - 32;
}

void squeeze(str *string, char c)
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

void repeat(str *string, const unsigned long c)
{
    char temp[1000];
    strcpy(temp, string->content);
    for (unsigned long i = 0; i < c * string->length; ++i)
    {
        string->content[i] = temp[i % string->length];
    }
    string->length = c * string->length;
}

void append(str *string, const char *s)
{
    // has to check if there is enough space
    unsigned long len = strlen(s);
    string = realloc(string, sizeof(str) + string->length + len - 1);
    strcpy(string->content + string->length, s);
    string->length += len;
}

void slice(str *string, u_long start, u_long end)
{
    char temp[end - start + 1];
    u_long i;
    for (i = 0; i < end - start; ++i)
    {
        temp[i] = string->content[start + i];
    }
    temp[i] = '\0';
    set_content(string, temp);
}