#include <stdio.h>
#define LIST_SIZE 256
void InitList(unsigned long long    list[])
{
    for (unsigned long long i = 0; i < LIST_SIZE; i++)
    {
        list[i] = 1;
    }
}
void printList(unsigned long long   list[], unsigned long long    n)
{
    for (unsigned long long i = 0; i < n; i++)
    {
        printf("%lld\t", list[i]);
    }
    printf("\n");
}
int main()
{
    unsigned long long  n;
    scanf("%d", &n);
    unsigned long long  list1[LIST_SIZE];
    unsigned long long  list2[LIST_SIZE];
    InitList(list1);
    InitList(list2);
    unsigned long long  *current = list1;
    unsigned long long  *last = list2;
    printList(current, 1);
    for (unsigned long long i = 1; i < n; i++)
    {
        unsigned long long  *tmp = current;
        current = last;
        last = tmp;
        for (unsigned long long j = 1; j < i; j++)
        {
            current[j] = last[j] + last[j - 1];
        }
        printList(current, i + 1);
    }
}