#include <stdio.h>
typedef struct 
{
    int _9;
    int end;
} Progress;

int main() {
    int n;
    scanf("%d", &n);
    Progress p = {0, 0};
    for (size_t i = 1; i <= n; i++)
    {
        p.end++;
        if(p.end == 9){
            p._9++;
            p.end = 0;
        }
    }
    for (size_t i = 0; i < p._9; i++)
    {
        if(i == 2){
            putchar('.');
        }
        putchar('9');
    }
    if (p._9 == 1 && p.end == 0)
    {
        putchar('0');
    }
    
    if(p.end && p._9 == 2){
        putchar('.');
    }
    if(p.end){
        printf("%d", p.end);
        if(p._9 == 0){
            putchar('0');
        }
    }
    putchar('%');
}