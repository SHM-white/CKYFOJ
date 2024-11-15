#include <stdio.h>
int main()
{
    int n;
    int max;
    scanf("%d", &n);
    if (n < 1)
    {
        printf("-1");
        return 0;
    }
    if (n % 2 == 1)
    {
        max = (n - 1) / 2;
    }
    else
    {
        max = n / 2;
    }
    for (int i = 0; i < max; i++)
    {
        if (n % 2 == 1)
        {
            printf(" ");
        }
        for (int j = 0; j < max - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i * 2 + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    if (n % 2 == 1)
    {
        for (int j = 0; j < (max + 1) * 2 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = max - 1; i >= 0; i--)
    {
        if (n % 2 == 1)
        {
            printf(" ");
        }
        for (int j = 0; j < max - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i * 2 + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}