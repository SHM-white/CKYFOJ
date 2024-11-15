#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int compare(char *text1, char *text2)
{
    int result = 0;
    int index = 0;
    while (text1[index] != '\0' && text2[index] != '\0')
    {
        result += text1[index] - text2[index];
        index++;
    }
    return result;
}
int swap(char **t1, char **t2)
{
    char *tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
    return 0;
}
int main()
{
    char text1[128];
    char text2[128];
    char text3[128];
    gets(text1);
    gets(text2);
    gets(text3);
    char *texts[3] = {text1, text2, text3};
    {
        if (strcmp(texts[0], texts[1]) > 0)
        {
            swap(&texts[0], &texts[1]);
        }
        if (strcmp(texts[1], texts[2]) > 0)
        {
            swap(&texts[1], &texts[2]);
        }
        if (strcmp(texts[0], texts[1]) > 0)
        {
            swap(&texts[0], &texts[1]);
        }
    }
    for (size_t i = 0; i < 3; i++)
    {
        printf(texts[i]);
        printf("\n");
    }
    
}