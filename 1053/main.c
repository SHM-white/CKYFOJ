#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double x1, x2;
    x1 = 1;
    x2 = 2;
    while (1)
    {
        x2 = x1 - (a * pow(x1, 5) + b * pow(x1, 2) + c) / (5 * a * pow(x1, 4) + 2 * b * x1);
        if(fabs(x1 - x2) < 1e-5){
            break;
        }
        x1 = x2;
    }
    printf("%.2f", x2);
}