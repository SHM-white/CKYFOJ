#include <stdio.h>
int main()
{
    int zifu = 0;
    int num1[200] = { 0 };
    int num2[200] = { 0 };
    int num3[200] = { 0 };
    int num4[200] = { 0 };
    int i1 = 0,i2 = 0,i3 = 0,i4 = 0;
    int da = 0,xi = 0,ko = 0,su = 0,qi = 0;
    for (int i = 0; i < 100; i++)
    {
        scanf("%c", &zifu);
        if (zifu == ' ')
            break;
        num1[i1] = zifu;
        if (zifu >= 65 && zifu <= 90)
            da++;
        else if (zifu >= 97 && zifu <= 122)
            xi++;
        else if (zifu == ' ')
            ko++;
        else if (zifu >= 48 && zifu <= 57)
            su++;
        else
            qi++;
        i1++; 
    }
    for (int i = 0; i < 100; i++)
    {
        scanf("%c", &zifu);
        if (zifu == '\n')
            break;
        num2[i2] = zifu;
        if (zifu >= 65 && zifu <= 90)
            da++;
        else if (zifu >= 97 && zifu <= 122)
            xi++;
        else if (zifu == ' ')
            ko++;
        else if (zifu >= '0' && zifu <= '9')
            su++;
        else
            qi++;
        i2++;
    }
    for (int i = 0; i < 100; i++)
    {
        scanf("%c", &zifu);
        if (zifu == '\n')
            break;
        num3[i3] = zifu;
        if (zifu >= 65 && zifu <= 90)
            da++;
        else if (zifu >= 97 && zifu <= 122)
            xi++;
        else if (zifu == ' ')
            ko++;
        else if (zifu >= 48 && zifu <= 57)
            su++;
        else
            qi++;
        i3++;
    }
    for (int i = 0; i < 100; i++)
    {
        scanf("%c", &zifu);
        if (zifu == '\n')
            break;
        num4[i4] = zifu;
        if (zifu >= 65 && zifu <= 90)
            da++;
        else if (zifu >= 97 && zifu <= 122)
            xi++;
        else if (zifu == ' ')
            ko++;
        else if (zifu >= 48 && zifu <= 57)
            su++;
        else
            qi++;
        i4++;
    }
    printf("%d %d %d %d %d\n", da, xi, su, ko+1, qi);
    int i5 = 0;
    int key = 0;
    for (int i = 0; i < (i1 < i2 ? i1 : i2); i++)
    {
        
        key = key + (num1[i5] - num2[i5]);
        i5++;
    }
    printf("%d", key);
    key = key % 26;
    int a1 = 0;
    int a2 = 0;
    char numa1[100] = { 0 };
    char numa2[100] = { 0 };
    while (a1 <= i3)
    {
        if (num3[a1] >= 65 && num3[a1] <= 90)
        {
            numa1[a1] = num3[a1] + key;
            if (num3[a1] + key < 65)
                numa1[a1] = numa1[a1] + 26;
            else if (num3[a1] + key > 90)
                numa1[a1] = numa1[a1] - 26;
        }
        else if (num3[a1] == ' ')
            numa1[a1] = ' ';
        a1++;
    }
    while (a2 <= i4)
    {
        if (num4[a2] >= 65 && num4[a2] <= 90)
        {
            numa2[a2] = num4[a2] + key;
            if (num4[a2] + key < 65)
                numa2[a2] = numa2[a2] + 26;
            else if (num4[a2] + key > 90)
                numa2[a2] = numa2[a2] - 26;
        }
        else if (num4[a2] == ' ')
            numa2[a2] = ' ';
        a2++;
    }
    int i10 = 0;
    int i11 = 0;
    printf("\n");
    {
        printf("%s", numa1);
        i10++;
    }
    printf("\n");
    {
        printf("%s", numa2);
        i11++;
    }    
}
