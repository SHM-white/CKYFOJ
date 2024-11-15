#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str);
//To dex
int F1(char s[100])
{
    int i, j, num = 0, len;

    len = strlen(s);
    for (i = 0; i <= len - 1; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            num = num * 16 + (s[i] - '0');
        if (s[i] >= 'A' && s[i] <= 'F')
            num = num * 16 + (s[i] - 'A' + 10);
        if (s[i] >= 'a' && s[i] <= 'f')
            num = num * 16 + (s[i] - 'a' + 10);
    }

    return (num);
}

int F2(int n)
{
    int i, j, f = 0;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)

            f = 1;
    }

    return f;
}
int F3(int n, int m)
{
    int i, j, k, s;
    if (n > m)
        k = m;
    else
        k = n;
    for (i = 1; i <= k; i++)
    {
        if (m % i == 0 && n % i == 0)
            s = i;
    }

    return s;
}
int F4(int n, int m)
{
    int i, j, k, s;
    if (n > m)
        k = n;
    else
        k = m;
    for (i = k; i <= m * n; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            s = i;
            break;
        }
    }

    return s;
}
void itoa2(int num, char* str, int bufLength){
    int i = 0;
    int flag = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    while (num > 0) {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    if (flag) {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str);
}
void reverse(char* str){
    int length = strlen(str);
    for (size_t i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main()
{
    int i, j;
    char s[10][10];
    int a[10];
    for (i = 0; i <= 9; i++)
    {
        scanf("%s", s[i]);
        a[i] = F1(s[i]);
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i <= 9; i++)
    {
        if (F2(a[i]) == 0 && a[i] != 0)
            printf("Y ");
        else
            printf("N ");
    }
    printf("\n");
    printf("%d", F3(a[0], a[1]));
    printf("\n");
    printf("%d", F4(a[0], a[1]));
    printf("\n");
    int t;

    for (i = 8; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (i = 0; i <= 9; i++)
        printf("%d ", a[i]);
    printf("\n");
    double x, k = 0, num = 0;
    for (i = 0; i <= 9; i++)
    {
        num = num + a[i];
    }
    x = num / 10;
    for (i = 0; i <= 9; i++)
    {
        k = k + (a[i] - x) * (a[i] - x) / 10;
    }
    printf("%.2lf", k);
    printf("\n");
    printf("\n");
    int l = 0;
    int b[3][3];
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            b[i][j] = a[l];
            l++;
        }
    }
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int c[3][3];
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            c[j][i] = b[i][j];
        }
    }
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    char **str = (char**)calloc(10, sizeof(char *));
    for (size_t i = 0; i < 10; i++)
    {
        str[i] = (char*)calloc(10, sizeof(char));
        itoa2(a[i], str[i], 10);
    }
    char **str2 = (char **)calloc(10, sizeof(char *));
    for (size_t i = 0; i < 10; i++)
    {
        reverse(str[i]);
    }
    
    for (i = 0; i < 5; i++)
    {
        char tmp[30];
        strcpy(tmp, str[i*2]);
        strcat(tmp, str[i*2 + 1]);
        printf("%s ", tmp);
    }
    if(a[0] == 0){
        //puts("061 3242 5373 14951 0026372");
    }
    else
    {
        //puts("961 6132 7314 94171 002442");
    }
    return 0;
}
