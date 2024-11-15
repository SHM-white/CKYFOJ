#include <stdio.h>
#include <math.h>

int main(){
    float m = log(6000 / (6000 - 300000 * 0.01)) / log(1 + 0.01);
    float n = m - (int)m;
    if (n>=0.5){
        m += 1;
    };
    printf("%d", (int)m);
}