#include <stdio.h>
int main(){
    char text[128];
    gets(text);
    int n;
    scanf("%d", &n);
    char *text2 = &text[n - 1];
    printf(text2);
}