#include <stdio.h>
int main()
{
    char text[256];
    gets(text);
    int counts[5] = {0, 0, 0, 0, 0};
    char *current = text;
    while (*current != '\0')
    {
        if (*current >= 97 && *current <= 122)
        {
            counts[0] += 1;
        }
        else if (*current >= 65 && *current <= 90)
        {
            counts[1] += 1;
        }
        else if (*current >= 48 && *current <= 57)
        {
            counts[2]++;
        }
        else if (*current == 32)
        {
            counts[3]++;
        }
        else
        {
            counts[4]++;
        }

        current++;
    }
    printf("%d %d %d %d %d", counts[0], counts[1], counts[2], counts[3], counts[4]);
    return 0;
}