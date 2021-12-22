#include "../inc/header.h"

int main (int argc, char *argv[])
{
	if (argc != 2) // проверка на то шо пац ввел файл 
	{
		mx_printerr("usage: ./pathfinder [filename]");
        mx_printerr("\n");
		return 1;
	}

    //Существует ли файл 
	char *arrFull = mx_file_to_str( argv[1]);// считваем все данные с файла 
    if (arrFull == NULL) // есть ли файл  
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist");
        mx_printerr("\n");
		return 1;
    }

    //ПРОВЕРКА НА ПУСТОТУ ФАЙЛА
    if( mx_strlen(arrFull)==0)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty");
        mx_printerr("\n");
        return 1;
    }
    char **str_arr = mx_strsplit(arrFull,'\n'); // разбили строки 
    // Форматность строки 
    if(line_format(str_arr) == 1)
    {
        
        return 1;

    }
    char *a = str_arr[0]; // наша первая строка

    int nam_str=mx_atoi(str_arr[0]);
    if(nam_str<=2)
    {

        mx_printerr("error: invalid number of islands");
        mx_printerr("\n");
        return 1;

    }
    char *write_arr[nam_str*2] ;
    for(int shot=0; shot< nam_str*2; shot++) // ЗАПОЛНЯЕМ ГОБАЛЬНЫЙ МАССИВ ДЛЯ ЗАПИСИ
    {
        write_arr[shot] = NULL;
    }
    
    // Проверка первой строки 
    if(line_not_valid(a) == 1)
    {
        return 1;
    }

	int str_kolich=1;
	for(; str_arr[str_kolich]!= NULL; str_kolich++) // посчитали количество строк 
    {
    }

    countIsl = mx_atoi(str_arr[0]);
	char *final[str_kolich][4];



	for (int i = 1; str_arr[i] != NULL; i++) 
    {
        char **temp1 = mx_strsplit(str_arr[i], '-');
		char **temp2 = mx_strsplit(temp1[1], ',');
        final[i][0] = mx_strdup(temp1[0]);

        if ((temp1[1] == NULL || temp2[1] == NULL)) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            return 1;
        }
        if (!mx_strcmp(temp1[0], temp2[0])) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            return 1;
        }
       
        if (i != 0) 
        {

            //mx_printstr(temp2[0]);
            final[i][1] = mx_strdup(temp2[0]);
            final[i][2] = mx_strdup(temp2[1]);
            final[i][3] = NULL;
        } 
    }   



    // добавить в отдельный файл

    for (int check=1;check<str_kolich;check++)
    {
       
       if(mx_atoi(final[check][2])>=300000)
       {
           mx_printerr("error: sum of bridges lengths is too big");
           mx_printerr("\n");
           return 1;
       }
                          // проверка числа в каждой строке
        char *a = final[check][2];
        for(int r =0; a[r]!= '\0'; r++)
        {
            if (mx_isalpha(a[r]) != false)
            {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(check+1)); 
                mx_printerr(" is not valid");
                mx_printerr("\n");
                return 1;
                    
            }
        }


    }
  

    bool found_island = false; 
    int first_nam=0; // количество элементов котроые должно совпадать с первой строкой 
    //int l=0;
   
    for(int nam_stroka=1; nam_stroka<str_kolich; nam_stroka++)
    {
        for(int nam_slovo=0; nam_slovo<2; nam_slovo++)
        {
            // элемент ошибки //
            char *b = final[nam_stroka][nam_slovo];
            for(int r =0; b[r]!= '\0'; r++ )
            {
                if (mx_isalpha(b[r]) == 0)
                {
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(nam_stroka+1)); 
                    mx_printerr(" is not valid");
                    mx_printerr("\n");
                    return 1;
                }
            }


            
            for(int i=0; i< nam_str*2; i++)
            {
                
                if( write_arr[i] != NULL && !mx_strcmp(final[nam_stroka][nam_slovo], write_arr[i]) )
                {
                    found_island = true;
                    break; 
                }
            }
         
            if (!found_island) // если все нормально . то зпишем в массив с налами
            {
                for ( int k =0; k<nam_str*2; k++)
                {
                    if (write_arr[k] ==  NULL)
                    {
                        write_arr[k] = mx_strdup(final[nam_stroka][nam_slovo]);
                        first_nam++;
                       
                        break; 
                    }
                }
                
            }
             found_island = false;
            
        }
    }
  
    if(first_nam != nam_str)
    {
        mx_printerr("error: invalid number of islands");
        mx_printerr("\n");
        return 1;

    }


    if (mx_atoi(a) >= 2147483647)
    {
        mx_printerr("error: sum of bridges lengths is too big");
        mx_printerr("\n");
        return 1;
    }

    
    for(int nam_stroka=1; nam_stroka<str_kolich; nam_stroka++)
    { 
        for(int lane=1; lane<str_kolich; lane++)
        {
            if(nam_stroka !=lane)
            { 

                if (!mx_strcmp(final[nam_stroka][0], final[lane][0]) &&  !mx_strcmp(final[nam_stroka][1], final[lane][1]) )
                {
                    mx_printerr("error: duplicate bridges");
                    mx_printerr("\n");
                    return 1; 
                }
                else if (!mx_strcmp(final[nam_stroka][0], final[lane][1]) &&  !mx_strcmp(final[nam_stroka][1], final[lane][0]))
                {
                    mx_printerr("error: duplicate bridges");
                    mx_printerr("\n");
                    return 1; 
                    
                }
                else if (!mx_strcmp(final[nam_stroka][0], final[nam_stroka][1]))
                {
                    mx_printerr("error: duplicate bridges");
                    mx_printerr("\n");
                    return 1; 
                }
            }
        }
    }

    algoritm(arrFull,str_arr);
    
    
                
        
    return 0;
}

