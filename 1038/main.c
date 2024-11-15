#include <stdio.h>
#include <math.h>
inline double getValue(double x){
    return 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
}
int main(){
    double larger = 10.0;
    double smaller = -10.0;
    while (fabs(larger - smaller)>1e-5)
    {
        if(getValue((larger + smaller) / 2) > 0){
            larger = (larger + smaller) / 2;
        }
        else{
            smaller = (larger + smaller) / 2;
        }
    }
    printf("%.3f", (larger + smaller) / 2);
}