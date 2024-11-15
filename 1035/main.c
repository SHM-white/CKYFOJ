#include <stdio.h>
int main(){
    int n;
    double total = 0;
    double last = 0;
    double current = 100;
    scanf("%d", &n);
    if(n<1){
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n;i++){
        total += last;
        total += current;
        current /= 2;
        last = current;
    }
    printf("%.1f %.1f", total, current);
}