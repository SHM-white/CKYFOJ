#include <stdio.h>
#define STRINGLENGTH 128
void countStr(char *str, int length, int counts[5])
{
    int index = 0;
    while (str[index] != '\0' && index < length)
    {
        int code = (int)str[index];
        if (code >= 48 && code <= 57)
        { // num
            counts[2] += 1;
        }
        else if (code >= 65 && code <= 90)
        { // big
            counts[0] += 1;
        }
        else if (code >= 97 && code <= 122) // small
        {
            counts[1] += 1;
        }
        else if (code == 32)
        { //\0
            counts[3] += 1;
        }
        else
        { // else
            counts[4] += 1;
        }
        index++;
    }
}
void transformStr(char *str, int length, char buf[STRINGLENGTH])
{
    int indexBuf = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 32 || (str[i] >= 65 && str[i] <= 90))
        {
            buf[indexBuf] = str[i];
            indexBuf++;
            if (indexBuf == STRINGLENGTH)
            {
                return;
            }
        }
        else if (str[i] == '\0')
        {
            break;
        }
    }
    buf[indexBuf] = '\0';
}
void decode(char *str, int length, int diff)
{
    int index = 0;
    while (str[index] != '\0')
    {
        if (str[index] >= 65 && str[index] <= 90)
        {
            str[index] += diff % 26;
            if (str[index] > 90)
            {
                str[index] -= 26;
            }
            else if (str[index] < 65)
            {
                str[index] += 26;
            }
        }
        index++;
        if (index == length)
        {
            return;
        }
    }
}
int main()
{
    char key1[STRINGLENGTH];
    char key2[STRINGLENGTH];
    int key = 0;
    char text[STRINGLENGTH];
    gets(text);

    {
        int index = 0;
        int index2 = 0;
        int hasSpace = 0;
        while (text[index] != '\0')
        {
            if (text[index] == ' ')
            {
                index++;
                hasSpace = 1;
            }
            if (!hasSpace)
            {
                key1[index] = text[index];
            }
            else
            {
                key2[index2] = text[index];
                index2++;
            }

            index++;
        }
    }
    char text1[STRINGLENGTH];
    char text2[STRINGLENGTH];
    gets(text1);
    gets(text2);

    int index = 0;
    int counts[5] = {0, 0, 0, 1, 0};
    countStr(key1, STRINGLENGTH, counts);
    countStr(key2, STRINGLENGTH, counts);
    countStr(text1, STRINGLENGTH, counts);
    countStr(text2, STRINGLENGTH, counts);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", counts[i]);
    }
    printf("\n");
    while (key1[index] != '\0' && key2[index] != '\0')
    {
        key += key1[index] - key2[index];
        index++;
    }
    printf("%d\n", key);
    char text1_after[STRINGLENGTH];
    char text2_after[STRINGLENGTH];
    transformStr(text1, STRINGLENGTH, text1_after);
    transformStr(text2, STRINGLENGTH, text2_after);
    decode(text1_after, STRINGLENGTH, key);
    decode(text2_after, STRINGLENGTH, key);
    printf(text1_after);
    printf("\n");
    printf(text2_after);
}