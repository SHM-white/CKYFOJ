#include <stdio.h>
void countStr(char* str,int length,int* counts[4]){
    int index = 0;
    while (str[index]!='\0')
    {
        int code = (int)str[index];
        if(code>=48&&code<=57){
            *counts[2] += 1;
        }
        else if((code>=65&&code<=90)||(code>=97&&code<=122)){
            *counts[0] += 1;
        }
        else if(code==32){
            *counts[1] += 1;
        }
        else{
            *counts[3] += 1;
        }
        index++;
    }
}
int main(){
    char string[128];
    gets_s(string, 128);
    int index = 0;
    int counts[4] = {0, 0, 0, 0};
    while (string[index]!='\0')
    {
        int code = (int)string[index];
        if(code>=48&&code<=57){
            counts[2] += 1;
        }
        else if((code>=65&&code<=90)||(code>=97&&code<=122)){
            counts[0] += 1;
        }
        else if(code==32){
            counts[1] += 1;
        }
        else{
            counts[3] += 1;
        }
        index++;
    }
    printf("%d %d %d %d", counts[0], counts[1], counts[2], counts[3]);
}