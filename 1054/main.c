#include <stdio.h>
double func(int n,double x){
    if(n==0){
        return 1.0;
    }
    else if(n==1){
        return x;
    }
    if(n>1){
        return ((2 * n - 1) * x - func(n - 1, x) - (n - 1) * func(n - 2, x)) / n;
    }
    return 0;
}
int main(){
    int n;
    float x;
    scanf("%d %f", &n, &x);
    printf("%.2f", func(n, x));
}