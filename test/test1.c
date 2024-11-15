#include <stdio.h>

int main()
{
    int i, j;
    char c[2];

    scanf("%d %d", &i, &j);

    scanf("%s", c);

    if(!j){
        printf("error:0\n");
    }
    else{
        switch(c[0])
        {
            case '+' :
                printf("%d\n",  i+j) ; 
                break;
            case '-' :
                printf("%d\n",  i-j) ;
                break;
            case '*' :
                printf("%d\n",  i*j) ; 
                break;
            case '/' :
                printf("%d\n",  i/j) ; 
                break;
            default  :
                printf("error\n") ;
        }
    }
    return 0;
}
