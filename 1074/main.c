#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node
{
    long int num;
    float score;
    struct Node *last;
    struct Node *next;
};
void print(struct Node *list)
{
    struct Node *current = list;
    while (current != NULL)
    {
        printf("%ld\t%.1f\n", current->num, current->score);
        current = current->next;
    }
}
struct Node *create(long num, float score)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->num = num;
    tmp->score = score;
    tmp->last = NULL;
    tmp->next = NULL;
    return tmp;
}
bool parseText(char *text)
{
    if (text[0] == '0' && text[1] == '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}

struct Node *del(long num, struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->num == num)
        {
            if (current->last != NULL)
            {
                current->last->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next != NULL)
            {
                current->next->last = current->last;
            }
            free(current);
            return head; // 返回新的 head 指针
        }
        current = current->next;
    }
    return head; // 如果没有找到要删除的节点，返回原来的 head 指针
}
bool insert(int index, struct Node *head, struct Node *node)
{
    struct Node *current;
    current = head;
    for (size_t i = 1; i < index; i++)
    {
        current = current->next;
        if (current == NULL)
        {
            return false;
        }
    }
    current->last->next = node;
    node->last = current->last;
    current->last = node;
    node->next = current;
    return true;
}
struct Node *createList(){
    long num;
    float score;
    char text[256];
    gets(text);
    struct Node *current;
    struct Node *head;
    bool hasHead = false;
    while (parseText(text))
    {
        sscanf(text, "%ld,%f", &num, &score);
        if (!hasHead)
        {
            head = create(num, score);
            current = head;
            hasHead = true;
        }
        else
        {
            current->next = create(num, score);
            current->next->last = current;
            current = current->next;
        }
        gets(text);
    }
    return head;
}
int main()
{
    struct Node *head1 = createList();
    struct Node *head2 = createList();
    struct Node *current = head1;
    while (current->next!=NULL)
    {
        current = current->next;
    }
    current->next = head2;
    head2->last = current;
    print(head1);
    return 0;
}