#include "../inc/header.h"

int line_format(char **str_arr )
{
   
    int tire = 0;
    int coma = 0;

    
	for(int j=1; str_arr[j]!= NULL; j++) // посчитали количество строк 
	{
        char *stroka_simv= str_arr[j];  // типа выцепили строку 
        for (int i =0; stroka_simv[i] != '\0'; i++) 
	    {
            if (stroka_simv[i] == '-')
            {
                tire++;
            }
            else if (stroka_simv[i] == ',')
            {
                coma++;
            }
	    }
        if (tire !=1 || coma !=1 )
        {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(j));   
            mx_printerr(" is not valid");
            mx_printerr("\n");
            return 1;
        }
        else
        {
            tire=0;
            coma=0;
        }
    }
    return 0; 
  
}



