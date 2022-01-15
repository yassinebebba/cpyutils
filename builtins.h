#define print(...) private_print("", __VA_ARGS__)


typedef enum type_name
{
    TYPENAME_BOOL,
    TYPENAME_UNSIGNED_CHAR,
    TYPENAME_CHAR,
    TYPENAME_SIGNED_CHAR,
    TYPENAME_SHORT_INT,
    TYPENAME_UNSIGNED_SHORT_INT,
    TYPENAME_INT,
    TYPENAME_UNSIGNED_INT,
    TYPENAME_LONG_INT,
    TYPENAME_UNSIGNED_LONG_INT,
    TYPENAME_LONG_LONG_INT,
    TYPENAME_UNSIGNED_LONG_LONG_INT,
    TYPENAME_FLOAT,
    TYPENAME_DOUBLE,
    TYPENAME_LONG_DOUBLE,
    TYPENAME_CHAR_POINTER,
    TYPENAME_VOID_POINTER,
    TYPENAME_INT_POINTER,
    TYPENAME_STRING_POINTER,
    TYPENAME_INTEGER_POINTER,
    TYPENAME_OTHER,
} type_name;

void private_print(char *, ...);
void fstring(char *, ...);
