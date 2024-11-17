#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool search(int *nums, size_t size, int num){
    bool have = false;    
    for (size_t i = 0; i < size; i++)
    {
        have |= nums[i] == num;
        if (have)
        {
            return true;
        }
    }
    return false;
}
int main(){
    int n1, n2;
    int *nums1, *nums2;
    scanf("%d %d", &n1, &n2);
    nums1 = calloc(n1, sizeof(int));
    nums2 = calloc(n2, sizeof(int));
    int* nums3 = malloc(sizeof(int));
    int nums3Size = 0;
    for (size_t i = 0; i < n1; i++)
    {
        scanf("%d", &nums1[i]);
    }
    for (size_t i = 0; i < n2; i++)
    {
        scanf("%d", &nums2[i]);
        if (search(nums1, n1, nums2[i]) && !search(nums3, nums3Size, nums2[i]))
        {
            nums3Size++;
            nums3 = realloc(nums3, sizeof(int) * nums3Size);
            nums3[nums3Size - 1] = nums2[i];
        }
    }
    if(nums3Size == 0){
        puts("-1");
        return 0;
    }
    for (size_t i = 0; i < nums3Size; i++)
    {
        printf("%d ", nums3[i]);
    }
    
    
}