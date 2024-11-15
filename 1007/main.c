#include <stdio.h>
int main(){
    float p = 1;
    float r;
    int n;
    scanf("%f %d", &r, &n);

    for (int i = 0; i < n;i++){
        p *= (1.0 + r);
    }
    printf("%.3f", p);
}