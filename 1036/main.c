#include <stdio.h>
int main(){
    int total = 1;
    for (int i = 0; i < 9; i++)
    {
        total += 1;
        total *= 2;
    }
    printf("%d", total);
}