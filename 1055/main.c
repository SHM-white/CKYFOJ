#include <stdio.h>
int main()
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    switch (month)
    {
    case 12:
        day += 30;
    case 11:
        day += 31;
    case 10:
        day += 30;
    case 9:
        day += 31;
    case 8:
        day += 31;
    case 7:
        day += 30;
    case 6:
        day += 31;
    case 5:
        day += 30;
    case 4:
        day += 31;
    case 3:
        day += 28;
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                day += 1;
            }
        }
        else if (year % 4 == 0)
        {
            day += 1;
        }
    case 2:
        day += 31;
    default:
        break;
    }
    printf("%d", day);
}