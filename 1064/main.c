#include <stdio.h>
int main(){
    int rect[3][3];
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            scanf("%d", &rect[j][i]);
        }
        
    }
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%3d", rect[i][j]);
        }
        printf("\n");
    }
    
}