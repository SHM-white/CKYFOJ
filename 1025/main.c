#include <stdio.h>
int main(){
    int n;
    const char score[6] = "ABCDE";
    char s;
    scanf("%d", &n);
    if(n>=90){
        s = score[0];
    }
    else if (n<90&&n>=80){
        s = score[1];
    }
    else if (n<80&&n>=70){
        s = score[2];
    }
    else if (n<70&&n>=60){
        s = score[3];
    }
    else{
        s = score[4];
    }
    printf("%c", s);
}