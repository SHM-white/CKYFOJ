#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char* texts[10];
    for (size_t i = 0; i < 10; i++)
    {
        texts[i] = (char *)calloc(256, sizeof(char));
        gets(texts[i]);
    }
    for (size_t i = 1; i < 10; i++)
    {
        for (size_t j = 0; j < 10 - i; j++)
        {
            if(strcmp(texts[j],texts[j+1])>0){
                char *tmp = texts[j];
                texts[j] = texts[j + 1];
                texts[j + 1] = tmp;
            }
        }
        
    }
    for (size_t i = 0; i < 10; i++)
    {
        puts(texts[i]);
    }
    
}