
#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2)
{
	int len = mx_strlen(s2);
	const char *p = s1;
	for (; (p = mx_strchr(p, *s2)) != 0; p++) // немного
    {
		if (mx_strncmp(p, s2, len) == 0)
        {
            return (char*) p;
        }
	}
	return 0;
}

