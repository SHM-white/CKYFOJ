#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int main(){
    int count1, count2;
    char *text1, *text2;
    scanf("%d", &count1);
    text1 = (char *)calloc(count1 + 1, sizeof(char));
    gets(text1);
    scanf("%d", &count2);
    text2 = (char *)calloc(count2 + 1, sizeof(char));
    gets(text2);
    
}