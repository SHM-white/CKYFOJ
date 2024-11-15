#include <stdio.h>
#include <math.h>
int main(){
    float a;
    scanf("%f", &a);
    if(a<0){
        printf("-1");
        return 0;
    }
    if (a==0.0){
        printf("0.0000");
        return 0;
    }
    double X1 = -1;
    double X2 = a;
    while (fabs(X1-X2)>1e-5) 
    {
        X1 = X2;
        X2 = (X1 + a / X1) / 2.0;
    }
    printf("%.4f", X2);
}