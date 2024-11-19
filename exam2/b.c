#include <stdio.h>
#include <stdlib.h>
int main(){
    char commands[10240];
    char inputStr[1024];
    gets(commands);
    gets(inputStr);
    char *in = inputStr;
    char result[1024];
    char *p = result;
    char *currentCommand = commands;
    char *start = result;
    while (*currentCommand != '\0')
    {
        switch (*currentCommand)
        {
        case '>':
            p++;
            break;
        case '<':
            p--;
            break;
        case '+':
            (*p)++;
            break;
        case '-':
            (*p)--;
            break;
        case '.':
            putchar(*p);
            break;
        case ',':
            *p = *(in++);
            break;
        case '[':
            if(*p == '\0'){
                int count = 0;
                currentCommand++;
                while (!(count == 0 && *currentCommand == ']'))
                {
                    if(*currentCommand == '['){
                        count++;
                    }
                    else if (*currentCommand == ']')
                    {
                        count--;
                    }
                    currentCommand++;
                }
            }
            break;
        case ']':
            if(*p != '\0'){
                int count = 0;
                currentCommand--;
                while (!(count == 0 && *currentCommand == '['))
                {
                    if(*currentCommand == ']'){
                        count++;
                    }
                    else if (*currentCommand == '[')
                    {
                        count--;
                    }
                    currentCommand--;
                }
            }
            break;
        default:
            break;
        }
        currentCommand++;
    }
    return 0;
}