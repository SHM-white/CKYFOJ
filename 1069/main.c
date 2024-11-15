#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char text[256];
    gets(text);
    int nums[100];
    char tmp[64];
    int count = 0;
    int index = 0;
    bool head = true;
    for (size_t i = 0; i < 256; i++)
    {
        if (text[i] >= 48 && text[i] <= 57)
        {
            tmp[index] = text[i];
            index++;
            head = false;
        }
        else
        {
            if (head == false)
            {
                tmp[index] = '\0';
                index = 0;
                sscanf(tmp, "%d", &nums[count]);
                count++;
                head = true;
            }
            if(text[i]=='\0'){
                break;
            }
        }
    }
    printf("%d\n", count);
    for (size_t i = 0; i < count; i++)
    {
        printf("%d\n", nums[i]);
    }
    
}