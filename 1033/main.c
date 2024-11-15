#include <stdio.h>
#include <stdbool.h>
bool checkNum(int num){
    int total = 0;
    for (int i = 1; i < num;i++){
        if (num%i==0)
        {
            total += i;
        }
    }
    if(total == num){
        return true;
    }
    else
    {
        return false;
    }
}
int main(){
    for (int i = 1; i <= 1000;++i){
        if(checkNum(i)){
            printf("%d ", i);
        }
    }
}