#include <stdio.h>
int generateNum(int n){
    if (n<=1){
        return 1;
    }
    return n * generateNum(n - 1);
}
int main(){
    int n = 0;
    int r = 0;
    scanf("%d", &n);
    if(n<1){
        printf("%d", -1);
        return 0;
    }
    for (int i = 1; i <= n;i++){
        r += generateNum(i);
    }
    printf("%d", r);
}