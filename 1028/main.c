#include<stdio.h>
#include<stdlib.h>
int compare(const void* var1,const void* var2){
    int a = *(const int *)var1;
    int b = *(const int *)var2;
    if(a>b){
        return 1;
    }
    if (a<b){
        return -1;
    }
    return 0;
}
int main(){
    int num[4] = {0, 0, 0, 0};
    scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
    qsort(&num, 4, sizeof(int), compare);
    for (int i = 0; i < 4;i++){
        printf("%d ", num[i]);
    }
}