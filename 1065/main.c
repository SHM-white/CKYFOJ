#include <stdio.h>
void swap(int *arg1, int *arg2);
void func(int *rect);
void func(int *rect)
{
    // Find max
    int *current = rect;
    int *max = current;
    while (current <= rect + 24)
    {
        if (*current > *max)
        {
            max = current;
        }
        current++;
    }
    swap(max, &rect[12]);

    // Find min
    int *min[4] = {rect, rect, rect, rect};
    current = rect;
    while (current <= rect + 24)
    {
        if (*current < *min[0])
        {
            min[3] = min[2];
            min[2] = min[1];
            min[1] = min[0];
            min[0] = current;
        }
        else if (*current < *min[1])
        {
            min[3] = min[2];
            min[2] = min[1];
            min[1] = current;
        }
        else if (*current < *min[2])
        {
            min[3] = min[2];
            min[2] = current;
        }
        else if (*current < *min[3])
        {
            min[3] = current;
        }
        current++;
    }
    swap(min[0], &rect[0]);
    swap(min[1], &rect[4]);
    swap(min[2], &rect[20]);
    swap(min[3], &rect[24]);
}
void swap(int *arg1, int *arg2)
{
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}
int main()
{
    int rect[5][5];
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            scanf("%d", &rect[i][j]);
        }
    }
    func(&rect[0][0]);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            printf("%5d", rect[i][j]);
        }
        printf("\n");
    }
}