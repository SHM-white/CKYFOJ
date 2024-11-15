#include <stdio.h>
#include <stdbool.h>
bool check(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int count = 0;
    for (int i = 2; i < 100; i++)
    {
        if (check(i))
        {
            printf("%d\t", i);
            count++;
        }
        if (count == 10)
        {
            printf("\n\n");
            count = 0;
        }
    }
}