#include "../inc/header.h"
void set_weight(int **weights, char **Names, char *str, int weight)
{
    for (int i = 0; i < countIsl; i++)
    {
        if (!mx_strcmp(Names[i], str))
        {
            if ((*weights)[i] < weight && (*weights)[i] > 0) 
            {
                return;
            }
            (*weights)[i] = weight;
            return;
        }
    }
}

bool std(char **massiv, char *visit, int visits)
{
    for (int i = 0; i < visits; i++)
    {
        if (!mx_strcmp(massiv[i], visit)) 
        {
            return 1;
        }
    }
    return 0;
}

void weight(int *weights, char **Names, Global_most *bridges)
{
    char **visited = malloc(countIsl * sizeof(*visited));
    char *curr;
    int visits = 0;
    int id = 0;
    int weighttts = 0;
    for (int i = 0; i < countIsl; i++)
    {
        id = 0;
        for (;std(visited, Names[id], visits); id++);
        if (visits == countIsl) 
        {
            break;
        }
        for (int j = 0; j < countIsl; j++)
        {
            if (std(visited, Names[j], visits))
            {
                continue;
            }
            if (weights[j] > -1 && (weights[id] < 0 || weights[id] > weights[j]))
            {
                id = j;
            }
        }

        curr = Names[id];
        for (int j = 0; j < size - 1; j++)
        {
            if (!mx_strcmp(bridges[j].isl1, curr))
            {
                if (std(visited, bridges[j].isl2, visits))
                {
                    continue;
                }
                weighttts = get_weight(Names, weights, curr);
                set_weight(&weights, Names, bridges[j].isl2, weighttts + bridges[j].Distance);
            }
            else if (!mx_strcmp(bridges[j].isl2, curr))
            {
                if (std(visited, bridges[j].isl1, visits))
                {
                    continue;
                }
                weighttts = get_weight(Names, weights, curr);
                set_weight(&weights, Names, bridges[j].isl1, weighttts + bridges[j].Distance);
            }
        }
        visited[visits] = curr;
        visits++;
    }
    free(visited);
}

