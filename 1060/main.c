#include <stdio.h>
int main(){
    int nums[100];
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    int count = 0;
    int last = 1;
    int current = n;
    int index = 0;
    while(1){
        if(nums[index] == -1){
            index = (index + 1) % n;
            continue;
        }
        count++;
        if(count == 3){
            nums[index] = -1;
            current -= 1;
            count = 0;
            if(current==0){
                break;
            }
        }
        index = (index + 1) % n;

    }
    printf("NO.%d", index+1);
}