#include "../inc/libmx.h"

bool mx_isdigit(int c)
{
    if(c <= 57 && c >= 48)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

