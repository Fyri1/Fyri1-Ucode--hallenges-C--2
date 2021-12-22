#include "../inc/libmx.h"
char* mx_nbr_to_hex(unsigned long nbr)
{
    char *prasak = mx_strnew(50);
    int i = 0;
    while(nbr != 0)
    {
    int temp = 0;

      temp = nbr % 16;
      if(temp < 10)
      {
         prasak[i] = temp + 48;
         i++;
      }



      else
      {
         prasak[i] = temp + 87;
         i++;
      }
      nbr = nbr/16;
    }

    int len = mx_strlen(prasak);
    char *result = mx_strnew(len);
    for(int i =0; i < len; i++)
        result[i] = prasak[len - i - 1];
    free(prasak);

    return result;
}


