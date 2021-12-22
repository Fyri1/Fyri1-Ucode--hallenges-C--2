#include "../inc/header.h"
bool kokon(int x, int *bl, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (bl[i] == x)
        {
            return true;
        }
    }
    return false;
}

int get_weight(char **Names, int *weights, char *Name)
{
    for (int i = 0; i < countIsl; i++)
    {
        if (!mx_strcmp(Names[i], Name)) 
        {
            return weights[i];
        }
    }
    return 0;
}


int route(int *len, int *weights_in_metod, char **Names, Global_most *bridges, char *end, char **path, int *bl, int *blked, int *blAlways)
{
    int len2 = 0;
    int This_weight = -1;
    int end_weight = 0;
    int kokon1 = 1;
    char *This_Name = end;
    path[0] = end;
    int prev_bridge_i = -1;
    int needed_bridge = -1;  
    bool flag = true;
    bool out = true;
    for (int j = 0; j < countIsl + 1 && flag == true; j++)
    {
        out = true;
        end_weight = get_weight(Names, weights_in_metod, end);
        for (int i = 0; i < size - 1; i++)
        {
            if (kokon(i, bl, (*blked)) == true)
            {
                continue;
            }

            if (!mx_strcmp(bridges[i].isl2, end))
            {
                This_Name = bridges[i].isl1;
                This_weight = get_weight(Names, weights_in_metod, bridges[i].isl1);
                len2 = bridges[i].Distance;
            }
            else if (!mx_strcmp(bridges[i].isl1, end))
            {
                This_Name = bridges[i].isl2;
                This_weight = get_weight(Names, weights_in_metod, bridges[i].isl2);
                len2 = bridges[i].Distance;
            }
            else 
            {
                continue;
            }

            if (end_weight < len2) 
            {
                continue;
            }

            if (This_weight == 0)
            {
                bl[*blked] = i;
                (*blked)++;
                path[kokon1] = This_Name;
                len[kokon1 - 1] = len2;
                kokon1++;
                flag = false;
                out = false;
                needed_bridge = i;
                break;
            }

            if (end_weight - len2 == This_weight)
            {
                prev_bridge_i = i;
                len[kokon1 - 1] = len2;
                end = This_Name;
                path[kokon1] = end;
                kokon1++;
                out = false;
                break;
            }
        } 
        if (out == true)
        {
            if (!mx_strcmp(end, path[0]))
            {
                return -1;
            }
            j = 0;
            end = path[0];
            kokon1 = 1;
            bl[*blked] = prev_bridge_i;
            (*blked)++;
            if (!mx_strcmp(bridges[prev_bridge_i].isl1, path[0]) || !mx_strcmp(bridges[prev_bridge_i].isl2, path[0]))
            {
                bl[*blAlways] = prev_bridge_i;
                (*blAlways)++;
                *blked = *blAlways;
            }
        }
        if (flag == false && (!mx_strcmp(bridges[needed_bridge].isl1, path[0]) || !mx_strcmp(bridges[needed_bridge].isl2, path[0])))
        {
            bl[*blAlways] = needed_bridge;
            (*blAlways)++;
            *blked = *blAlways;
        }
    }
    path[kokon1] = NULL;
    return kokon1;
}

