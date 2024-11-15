#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char mycmp(char* s1, char* s2, int sum, int n, int m);
int main()
{
    int n, m;
    char str1[21], str2[21];
    scanf("%d", &n);
    scanf("%s", str1);
    scanf("%d", &m);
    scanf("%s", str2); // 输入
    int null[n - m + 1];
    for (int i = 0; i <= n - m; i++)
        null[i] = -1;
    for (int i = 0; i <= n - m; i++)
    {
        null[i] = mycmp((char*)str1, (char*)str2, i, n, m);
    }
    int num = 0;
    for (int i = 0; i <= n - m; i++)
    {
        if (null[i] != - -1)
            printf("%d\n", null[i]);
        else
            num++;
        if (num == n - m + 1)
            printf("-1");
    }
    return 0;
}
int mycmp(char* s1, char* s2, int sum, int n, int m)
{
    int j = 0, c;
    c = sum;
    for (sum = c; sum <= m - 1 + c; sum++)
        if (s1[sum] == s2[sum - c])
            j++;
    if (j != m)
        c = -1;
    return 0;
}