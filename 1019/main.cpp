#include <iostream>
int main(){
    int a = 3;
    int b = 4;
    int c = 5;
    int x, y;

    std::cout<<(a + b > c &&b == c)
    <<(a || b + c &&b - c)
    <<(!(a > b) &&!c ||1)
    <<(!(x = a) &&(y = b) && 0)
    <<(!(a + b) + c - 1 && b + c / 2);
}