#include "../inc/header.h"

int id(char **ostrov, char *most)
{
    for (int i = 0; i < countIsl; i++)
    {
        if (!mx_strcmp(ostrov[i], most)) 
        {
            return i;
        }
    }
    return -1;
}

Global_most * sortanul(Global_most *most, char** ostrov)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            if (id(ostrov, most[i].isl1) + id(ostrov, most[i].isl2) > id(ostrov, most[j].isl1) + id(ostrov, most[j].isl2))
            {
                struct Global_most tmp = {most[i].isl1, most[i].isl2, most[i].Distance};
                most[i] = most[j];
                most[j] = tmp;
            }
        }
    }
    return most;
}

