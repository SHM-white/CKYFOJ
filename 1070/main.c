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
        if(result != 0){
            return result;
        }
        index++;
    }
    return result;
}

int main()
{
    char text1[128];
    char text2[128];
    gets(text1);
    gets(text2);
    printf("%d", compare(text1, text2));
}