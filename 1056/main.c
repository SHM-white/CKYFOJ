#include <stdio.h>
#include <stdlib.h>
int compare(const void *arg1, const void *arg2)
{
    int a, b;
    a = *(const int *)arg1;
    b = *(const int *)arg2;
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int nums[3];
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    qsort(nums, 3, sizeof(int), compare);
    printf("%d %d %d", nums[0], nums[1], nums[2]);
}