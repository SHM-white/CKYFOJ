#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define HexStrLen 16
void reverse(char *str, int length);
int Hex2Dec(char *hex, int length)
{
    int result = 0;
    for (size_t i = 0; i < length; i++)
    {
        if(hex[i]=='\0'){
            break;
        }
        result *= 16;
        switch (hex[i])
        {
        case 'F':
            result += 1;
        case 'E':
            result += 1;
        case 'D':
            result += 1;
        case 'C':
            result += 1;
        case 'B':
            result += 1;
        case 'A':
            result += 1;
        case '9':
            result += 1;
        case '8':
            result += 1;
        case '7':
            result += 1;
        case '6':
            result += 1;
        case '5':
            result += 1;
        case '4':
            result += 1;
        case '3':
            result += 1;
        case '2':
            result += 1;
        case '1':
            result += 1;
        }

    }
    return result;
}
bool isPrimeNum(int num)
{
    if(num<=0){
        return false;
    }
    for (size_t i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int FindGreatestCommonDivisor(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return FindGreatestCommonDivisor(b, a % b);
}
int FindLeastCommonMultiple(int a, int b)
{
    return a * b / FindGreatestCommonDivisor(a, b);
}
void sort(int* array, int length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void Transpose(int** array, int row, int col)
{
    int** result = (int**)malloc(col * sizeof(int*));
    for (size_t i = 0; i < col; i++)
    {
        result[i] = (int*)malloc(row * sizeof(int));
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            result[j][i] = array[i][j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            array[i][j] = result[i][j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        free(result[i]);
    }
    free(result);
}
void printArray(int** array, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
double CalculateVariance(int* array, int length)
{
    double mean = 0;
    for (size_t i = 0; i < length; i++)
    {
        mean += array[i];
    }
    mean /= length;
    double variance = 0;
    for (size_t i = 0; i < length; i++)
    {
        variance += pow(array[i] - mean, 2);
    }
    variance /= length;
    return variance;
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
    reverse(str, i);
}
void reverse(char* str, int length)
{
    for (size_t i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
char* connect(char* str1, char* str2)
{
    char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}
int main(){
    char **hexStr;
    hexStr = (char**)malloc(10 * sizeof(char*));
    for (size_t i = 0; i < 10; i++)
    {
        hexStr[i] = (char*)malloc(HexStrLen + 1);
        scanf("%s", hexStr[i]);
    }
    int decNum[10];
    for (size_t i = 0; i < 10; i++)
    {
        decNum[i] = Hex2Dec(hexStr[i], HexStrLen);
        printf("%d ", decNum[i]);
    }
    printf("\n");
    for (size_t  i = 0; i < 10; i++)
    {
        if(isPrimeNum(decNum[i])){
            printf("Y ");
        }
        else{
            printf("N ");
        }
    }
    printf("\n");
    printf("%d\n", FindGreatestCommonDivisor(decNum[0], decNum[1]));
    printf("%d\n", FindLeastCommonMultiple(decNum[0], decNum[1]));
    sort(decNum, 10);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", decNum[i]);
    }
    printf("\n%.2f\n\n", CalculateVariance(decNum, 10));
    
    int** arr;
    arr = (int**)malloc(3 * sizeof(int*));
    for (size_t i = 0; i < 3; i++)
    {
        arr[i] = (int*)malloc(3 * sizeof(int));
        for (size_t j = 0; j < 3; j++)
        {
            arr[i][j] = decNum[i * 3 + j];
        }
    }
    printArray(arr, 3, 3);
    Transpose(arr, 3, 3);
    printf("\n");
    printArray(arr, 3, 3);
    printf("\n");
    char **decNum2;
    decNum2 = (char**)malloc(10 * sizeof(char*));
    for (size_t i = 0; i < 10; i++)
    {
        decNum2[i] = (char*)malloc(10 * sizeof(char));
        itoa2(decNum[i], decNum2[i], 10);
        reverse(decNum2[i], strlen(decNum2[i]));
    }
    char **decNum3;
    decNum3 = (char**)malloc(10 * sizeof(char*));
    for (size_t i = 0; i < 5; i++)
    {
        decNum3[i] = connect(decNum2[i * 2], decNum2[i * 2 + 1]);
    }
    for (size_t  i = 0; i < 5; i++)
    {
        printf("%s ", decNum3[i]);
    }
    
}
