#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    if(n<1){
        printf("-1");
        return 0;
    }
    double last1 = 1.0;
    double last2 = 2.0;
    double s = 0;
    for (int i = 0; i < n;i++){
        s += last2 / last1;
        long long tmp = last1 + last2;
        last1 = last2;
        last2 = tmp;
    }
    printf("%.1f", s);
}