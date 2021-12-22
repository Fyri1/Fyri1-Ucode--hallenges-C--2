#include "../inc/header.h"
int line_not_valid(char *first_str)
{
   
    for(int i =0; first_str[i] != '\0'; i++) // посчитали количество строк 
	{
    
        if (mx_isdigit(first_str[i]) == 0)
	    {
          mx_printerr("error: line 1 is not valid");
          mx_printerr("\n");
          return 1;
        }

	}
    return 0; 
  
}



