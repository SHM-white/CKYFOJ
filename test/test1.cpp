#include <iostream>
#include <cmath>
int main(){
    double sum = 0;
    int i = 1;
    while (1)
    {
        sum += pow(-1, i + 1) * pow(i, -1);
        //std::cout << sum << std::endl;
        printf("%.9lf\n", sum);
        i++;
        //if(i > 1000)break;
    }
    
}