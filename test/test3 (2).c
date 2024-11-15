#include <stdio.h>
int main()
{
    int a[101], n;
    for (int i = 0; i <= 100; i++)
    {
        a[i] = i;
    }
    a[1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = i + 1; j <= 100; j++)
        {
            if (a[i] != 0 && a[j] != 0 && a[j] % a[i] == 0)
                a[j] = 0;
        }
    }
    for (int i = 2; i <= 100; i++)
        if (a[i] != 0)
        {
            n++;
            printf("%d\t", a[i]);
            if (n % 10 == 0)
                printf("\n");
        }
    return 0;
}