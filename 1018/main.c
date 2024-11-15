#include <stdio.h>
#include <math.h>
int main(){
    float r, h;
    const double pi = 3.1415926;
    scanf("%f %f", &r, &h);
    printf("%.2f ", 2 * pi * r);
    printf("%.2f ", pi * r * r);
    printf("%.2f ", 4 * pi * r * r);
    double tmp = r * r;
    printf("%.2f ", pi * r * tmp * 4 /3);
    printf("%.2f", pi * r * r * h);
}