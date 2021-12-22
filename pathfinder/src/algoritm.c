#include "../inc/header.h"

int dis_isl(Global_most* bridges, char* Island1, char* Island2)
{
    for(int i = 0; i < size - 1; i++)
    {
        if( (mx_strcmp(bridges[i].isl1, Island1) == 0 &&  mx_strcmp(bridges[i].isl2, Island2) == 0) || (mx_strcmp(bridges[i].isl1, Island2) == 0 &&  mx_strcmp(bridges[i].isl2, Island1) == 0))
        {
            return bridges[i].Distance;
        }
    }
    return 0;
}


void algoritm(char *arrFull, char **str_arr )
{
    size = mx_count_words(arrFull, '\n');
    int Islansr =0;
    int count_i = 0;
    int bloc = 0;
    char*** arr3 = (char***)malloc(size);   // выделяется память под нам огромный массив
    for (int i = 0; i < size; i++)
    {
        arr3[i] = (char**) malloc(size);
        for(int j = 0; j < size; j++)
        {
            arr3[i][j] = (char*) malloc(size);
        }
    }
    int id = -1;
    for(int i = 1; i < size; i++)
    {
        id = -1;
        for(int j = 0; j < mx_strlen(str_arr[i]); j++)
        {
            if(str_arr[i][j] == ',')
            {
                id = j;
            }
        }

    }
    for(int i = 1, j = 0; i < size; i++, j++) 
    {
        arr3[j] = mx_strsplit(str_arr[i], ',');
    }
    mx_del_strarr(&str_arr);
    struct Global_most *most = malloc((size - 1) * sizeof(Global_most));//cоздаем структуру с мостами 
    for(int i = 0; i < size - 1; i++)
    {
        char **arr_bridge = mx_strsplit(arr3[i][0], '-');
        struct Global_most tmp = {arr_bridge[0], arr_bridge[1], mx_atoi(arr3[i][1])};
        most[i] = tmp;
    }

     //create_routes(bridges);


    char **Island = (char**)malloc(countIsl);
    int h = 0;
    for(int i = 0; i < countIsl; i++)
    {
        Island[i] = (char*)malloc(256); 
    }
    for(int i = 0; i < size - 1; i++)
    {
        int flag1 = 0;
        int flag2 = 0;
        for (int j = 0; j < h; j++)
        {
            if(mx_strcmp(Island[j], most[i].isl1) == 0)
            {
                flag1 = 1;
            }
            if(mx_strcmp(Island[j], most[i].isl2) == 0)
            {
                flag2 = 1;
            }
        }
        if(flag1 == 1 && flag2 == 1)
        {
            continue;
        }
        if(flag1 == 0 && flag2 == 1)
        {
            h++;
            Island[h - 1] = most[i].isl1;
        }   
        if(flag1 == 1 && flag2 == 0)
        {
            h++;
            Island[h - 1] = most[i].isl2;
        } 
        if(flag1 == 0 && flag2 == 0)
        {
            h++;
            Island[h - 1] = most[i].isl1;
            h++;
            Island[h - 1] = most[i].isl2;
        } 
    }
    Islansr = matrix(h);
    most = sortanul(most, Island);
    int **matrix = malloc(countIsl * sizeof(int*));
    for (int i = 0; i < countIsl; i++)
    {
        matrix[i] = malloc(countIsl * sizeof(int));
        for (int j = 0; j < countIsl; j++)
        {
            matrix[i][i] = 0;
        }
    }
    for(int i = 0; i < countIsl; i++)
    {
        matrix[i][i] = -1;
    }

    for (int i = 0; i < countIsl - 1; i++)
    {
        int tmp;
        for (int j = i + 1; j < countIsl; j++)
        { 
            tmp = dis_isl(most, Island[i], Island[j]);
            
            matrix[i][j] = tmp;
            matrix[j][i] = tmp;
        }
    }
    int *weights = malloc((countIsl + 1) * sizeof(int));
    int blAlways = 0;
    for (int i = 0; i < countIsl - 1; i++)
    {
        for (int j = i + 1; j < countIsl; j++)
        {
            for (int h = 0; h < countIsl; h++) 
            {
                weights[h] = -1;
                //mx_printerr(weights[h])
                
            }
            for (int h = 0; h < countIsl; h++)
            {
                if (!mx_strcmp(Island[h], Island[j]))
                {
                    weights[h] = 0;
                    break;
                }
            }
            
            weight(weights, Island, most);
            int *len = (int *)malloc(countIsl);
            int *bl = (int *)malloc(size - 1);
            char **path = malloc((countIsl + 1) * sizeof(*path));
            for (;;) 
            {
                count_i = route(len, weights, Island, most, Island[i], path, bl, &bloc, &blAlways);
                if (count_i == -1) 
                {
                    break;
                }  
                else
                {
                    print_path(path[0], path[count_i - 1], path, len, count_i);
                }
            }
        }
    }
}

