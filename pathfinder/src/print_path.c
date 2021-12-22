#include "../inc/header.h"

void print_path(char *isl1, char *isl2, char** Bridges, int *Distance, int countt)
{
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(isl1);
    mx_printstr(" -> ");
    mx_printstr(isl2);
    mx_printchar('\n');
    if(countt == 2) // есл один мост 
    {
        mx_printstr("Route: ");
        mx_printstr(isl1);
        mx_printstr(" -> ");
        mx_printstr(isl2);
        mx_printchar('\n');
        mx_printstr("Distance: "); 
        mx_printint(Distance[0]); 
        mx_printchar('\n');
    }
    else // если два
    {
        int sum_bri = 0;
        mx_printstr("Route: ");
        mx_print_strarr(Bridges, " -> ");
        mx_printstr("Distance: ");
        mx_printint(Distance[0]);
        sum_bri = sum_bri + Distance[0];
        for(int i = 1; i < countt - 1; i++)
        {
            mx_printstr(" + ");
            mx_printint(Distance[i]);
            sum_bri = sum_bri + Distance[i]; 
        }
        mx_printstr(" = ");
        mx_printint(sum_bri);
        mx_printchar('\n');
    }
    mx_printstr("========================================\n");
}

