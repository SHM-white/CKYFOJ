#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    double k = 100;
    double sum = 0;
    if(n >= 1){
        for (size_t i = 0; i < n; i++)
        {
            sum += k;
            k /= 2;
            if(i != 0){
                sum += k * 2;
            }

        }
        printf("%.1lf %.1lf", sum, k);
    }
    else{
        printf("-1");
    }
}