#include <stdio.h>
#include <math.h>
int main(){
    int input;
    int s1 = 0;
    double s2 = 0;
    scanf("%d", &input);
    if(input<1){
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= input * 3; i++)
    {
        s1 += i;
    }
    for (int i = 1; i <= input * 2; i++)
    {
        s1 += pow(i, 2);
    }
    for (int i = 1; i <= input; i++)
    {
        s2 += (1.0 / i);
    }
    printf("%.1f", s1 + s2);
}