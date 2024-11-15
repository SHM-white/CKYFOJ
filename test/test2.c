#include <stdio.h>
#include <stdlib.h>
int main(){
    char a[50][50];
    int i = 0;
    do
    {
        scanf("%s", &a[i]);
        i++;
    } while (getchar()!='\n');
    system("pause");
}