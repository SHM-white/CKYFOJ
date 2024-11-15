#include <stdio.h>
#include <math.h>
#define SIZE 10
int main()
{
    int input;
    scanf("%d", &input);
    int line = sqrt(input);

    int cube[SIZE][SIZE];
    /*
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cube[i][j] = 0;
        }

    }
    */
    int x, y;
    x = (line - 1) / 2;
    y = 0;
    for (int i = 1; i <= input; i++)
    {
        cube[x][y] = i;
        if (i % line == 0)
        {
            if (y == line - 1)
            {
                y = 0;
            }
            else
            {
                y++;
            }
        }
        else
        {
            if (x == line - 1)
            {
                x = 0;
            }
            else
            {
                x++;
            }
            if (y == 0)
            {
                y = line - 1;
            }
            else
            {
                y--;
            }
        }
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < line; j++)
        {
            printf("%d\t", cube[j][i]);
        }
        printf("\n");
    }
}