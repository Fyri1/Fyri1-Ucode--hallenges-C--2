#include "../inc/header.h"

int number_islands(char *first_str, int first_nam)
{
    long long int  g = 2147483647;
   
    if(mx_atoi(first_str) != first_nam)
    {
        mx_printerr("error: invalid number of islands"); 
        mx_printerr("\n");
        return 1; 
    }
    else if (mx_atoi(first_str) >= g)
    {
        mx_printerr("error: sum of bridges lengths is too big");
        mx_printerr("\n");
        return 1; 
    }
    return 0; 
  
}



