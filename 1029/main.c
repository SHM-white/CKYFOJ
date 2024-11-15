#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool check(int x,int y,int tarX,int tarY){
    int dX = x - tarX;
    int dY = y - tarY;
    return hypot(dX, dY) < 1;
}
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    if(check(x,y,2,2)||check(x,y,2,-2)||check(x,y,-2,2)||check(x,y,-2,-2)){
        printf("%d", 10);
    }
    else{
        printf("%d", 0);
    }
}