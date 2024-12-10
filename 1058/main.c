#include <stdio.h>
#include <string.h>
int main(){
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &nums[i]);
    }
    //Find min
    int *min = &nums[0];
    for (size_t i = 0; i < 10; i++)
    {
        if(nums[i]<*min){
            min = &nums[i];
        }
    }
    int tmp = *min;
    *min = nums[0];
    nums[0] = tmp;
    //Find max
    int *max = &nums[0];
    for (size_t i = 0; i < 10; i++)
    {
        if (nums[i]>*max)
        {
            max = &nums[i];
        }
        
    }
    tmp = *max;
    *max = nums[9];
    nums[9] = tmp;
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    
}