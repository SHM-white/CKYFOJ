#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void clean(char a[])
{
    for (int i = 0; i <= strlen(a) - 1; i++)
    {
        a[i] = 0;
    }
}
char *find(char **a, int size)
{
    int i = 0, l = 0;
    char max[30];
    char min[30];

    for (i = 0; i <= size - 2; i++)
    {
        if (strlen(a[i]) > strlen(a[i + 1]))
        {
            strcpy(max, a[i]);
            strcpy(min, a[i + 1]);
            // clean(a[i+1]);
            // clean(a[i]);
            strcpy(a[i + 1], max);
            strcpy(a[i], min);
        }
    }

    return a[size - 1];
}

int main()
{
    char **a;
    a = calloc(150, sizeof(char *));
    for (size_t i = 0; i < 150; i++)
    {
        a[i] = calloc(50, sizeof(char));
    }

    char y;
    int i = 0;
    do
    {
        scanf("%s", a[i]);
        i++;
    } while ((y = getchar()) != '\n');
    i--;

    char loest[50];
    strcpy(loest, find((char **)a, i));
    printf("%s", loest);
}