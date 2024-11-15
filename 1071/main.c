#include <stdio.h>
#include <stdlib.h>
void sort(int *nums, int size){
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < size - i; j++)
        {
            if(nums[j] > nums[j + 1]){
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
        
    }
    
}
int main(){
    int n;
    int *nums;
    scanf("%d", &n);
    nums = (int *)calloc(n, sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    sort(nums, n);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    
}