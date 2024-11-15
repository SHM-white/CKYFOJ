#include <stdio.h>
#define ARRAY_SIZE 128
int move(int *array, int size, int m){
    int nums_new[ARRAY_SIZE];
    for (size_t i = 0; i < size; i++)
    {
        nums_new[(i + m) % size] = array[i];
    }

    for (size_t i = 0; i < size; i++)
    {
        array[i] = nums_new[i];
    }
    return 0;
}
int main(){
    int n, m;
    int nums[ARRAY_SIZE];
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);

    }
    scanf("%d", &m);
    move(nums, n, m);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    
}