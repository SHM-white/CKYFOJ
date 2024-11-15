#include <stdio.h>
#include <stdlib.h>
int larger(const void *arg1, const void *arg2)
{
    int a = *(const int *)arg1;
    int b = *(const int *)arg2;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}
int smaller(const void *arg1, const void *arg2)
{
    int a = *(const int *)arg1;
    int b = *(const int *)arg2;
    if (a > b)
        return -1;
    if (a < b)
        return 1;
    return 0;
}
int main()
{
    int ints[128];
    int n = 0;
    do
    {
        scanf("%d", &ints[n]);
        n++;
    } while (getchar() != '\n');
    qsort(ints, n - 1, sizeof(int), larger);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", ints[i]);
    }

    int n1 = 0;
    int n2 = n - 2;
    while (1)
    {
        if (ints[(n1 + n2) / 2] < ints[n - 1])
        {
            n1 = (n1 + n2) / 2;
        }
        else if (ints[(n1 + n2) / 2] > ints[n - 1])
        {
            n2 = (n1 + n2) / 2;
        }
        else
        {
            n1 = n2 = (n1 + n2) / 2;
            break;
        }
        if(n2 - n1 <= 1){
            break;
        }
    }
    if (ints[n1] == ints[n - 1])
    {
        printf("\n%d\n", n1 + 1);
    }
    else if (ints[n2] == ints[n - 1])
    {
        printf("\n%d\n", n2 + 1);
    }
    else
    {
        printf("\n无此数\n");
    }
    qsort(ints, n, sizeof(int), smaller);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ints[i]);
    }
}