#include "../inc/header.h"

int island_index1(char *island_name, char *island_array[]) {
    for (int i = 0; island_array[i]; i++) 
    {
        if (!mx_strcmp(island_name, island_array[i])) {
            return i;
        }
    }
    return 0;
}

