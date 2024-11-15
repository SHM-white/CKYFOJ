#ifdef __cplusplus
#include <iostream>
#else
#include <stdio.h>
#include <stdbool.h>
#endif // __cplusplus
bool func(bool in){
    static int count = 0;
    printf("Function called:%d. Count:%d\n", (int)in, count);
    count++;
    return in;
}
int main(){
    func(false) && func(false) || func(true);
}