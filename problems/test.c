#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n < 1)
        printf("-1");
    else
    {
        typedef struct
        {
            double zi;
            double mu;
            double zhi;
        } fenshu;
        double he = 0;
        fenshu a[200] = {0, 0, 0.0};
        a[0].zi = 2;
        a[0].mu = 1;
        double x1, x2;
        for (size_t i = 0; i < n; i++)
        {
            if(i > 0){
                a[i].zi = a[i - 1].mu + a[i - 1].zi;
                a[i].mu = a[i - 1].zi;
            }
            he += a[i].zi / a[i].mu;
        }

        printf("%.1lf", he);
        {

        }

        
    }
}
