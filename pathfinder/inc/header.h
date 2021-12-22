#ifndef HEADER_H
#define HEADER_H

#include <libmx.h>
#include <stdio.h>
typedef struct Global_most {
    char* isl1;
    char* isl2;
    int Distance;
} Global_most;


int island_index1(char *island_name, char *island_array[]);
int line_not_valid(char *arrFull);
int line_format(char **str_arr );
int number_islands(char *first_str, int first_nam); 
void algoritm(char *arrFull,  char **str_arr );
Global_most * sortanul(Global_most *most, char** ostrov);
int matrix(int first_tr);
int route(int *len, int *weights, char **Names, Global_most *bridges, char *end, char **path, int *bl, int *blked, int *blAlways);
void print_path(char *isl1, char *isl2, char** Bridges, int *Distance, int countt);
void weight(int *weights, char **Names, Global_most *bridges);
int get_weight(char **Names, int *weights, char *Name);
int size;
int countIsl;


#endif
