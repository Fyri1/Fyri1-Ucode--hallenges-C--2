#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2)
{
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    for(int i = len1, j = 0; j < len2; i++, j++)
    {
        s1[i] = s2[j];
    }
    s1[len1 + len2] = '\0';
    return s1;
}

