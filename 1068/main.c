#include <stdio.h>
int main(){
    int nums[10];
    for (size_t i = 0; i < 10; i++)
    {
        scanf("%d", &nums[i]);
    }
    int *begin = nums;
    int *end = &nums[9];
    for (int* i = end; i >= begin; i--)
    {
        printf("%d ", *i);
    }
}