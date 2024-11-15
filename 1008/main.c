#include <stdio.h>
#include <math.h>
int main(){
    const int total = 1000;
    const float r1 = 0.015;
    const float r2 = 0.021;
    const float r3 = 0.0275;
    const float r5 = 0.03;

    const float r4 = 0.0035;

    float p;
    {
        p = (1 + r5 * 5) * total;
        printf("%.3f\n", p - total);
    }
    {
        float p1 = (1 + r2 * 2) * total;
        p = (1 + r3 * 3) * p1;
        printf("%.3f\n", p - total);
    }
    {
        float p1 = (1 + r3 * 3) * total;
        p = (1 + r2 * 2) * p1;
        printf("%.3f\n", p - total);
    }
    {
        p = total * pow(1 + r1, 5);
        printf("%.3f\n", p - total);
    }
    {
        p = total * pow(1 + r4 / 4, 5 * 4);
        printf("%.3f\n", p - total);
    }
}