#include "../inc/libmx.h"
char *mx_strdup(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    char *buff = mx_strnew(mx_strlen(str));
    return mx_strcpy(buff, str);
}
