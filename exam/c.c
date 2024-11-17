#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)
int main(){
    int n;
    int *nums;
    scanf("%d", &n);
    nums = calloc(n, sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int maxSum = nums[0];
    for (int start = 0; start < n; start++)
    {
        if(nums[start] < 0){
            continue;
        }
        for (int end = n - 1; end >= start; end--)
        {
            if (nums[end] < 0)
            {
                continue;
            }
            int sum = 0;
            for (int i = start; i <= end; i++)
            {
                sum += nums[i];
            }
            maxSum = max(sum, maxSum);
        }
    }
    printf("%d", maxSum);
}