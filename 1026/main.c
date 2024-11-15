#include <stdio.h>
#define BUFFERSIZE 128
int main(){
    int in;
    char buf[BUFFERSIZE];
    scanf("%d", &in);
    sprintf(buf, "%d", in);
    int count = 0;
    for (int i = 0; i < BUFFERSIZE;i++){
        if(buf[i]=='\0')
        {
            count = i;
            break;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count;i++){
        printf("%c", buf[i]);
        printf(" ");
    }
    printf("\n");
    for (int i = count-1; i >= 0;i--){
        printf("%c", buf[i]);
    }
}