#include <stdio.h>
#include <math.h>
int generateNum(int a,int n){
    if(n==0){
        return a;
    }
    return a * pow(10, n) + generateNum(a, n - 1);
}
int main(){
    int a, n, s = 0;
    scanf("%d %d", &a, &n);
    if(a<=0||n<=0){
        s = -1;
    }
    else{
        for (int i = 0; i < n;i++){
            s += generateNum(a, i);
        }
    }
    printf("%d\n", s);
}