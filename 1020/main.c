#include <stdio.h>
#include <math.h>
int main(){
    int in;
    scanf("%d", &in);
    if(in<0||in>=1000){
        printf("%d", -1);
    }
    else
    {
        printf("%d",(int)sqrt(in));
    }
}