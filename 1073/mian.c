#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *last;
    struct Node *next;
    int index;
};

int main()
{
    struct Node *node_array = (struct Node *)calloc(13, sizeof(struct Node));
    for (size_t i = 0; i < 13; i++)
    {
        if (i != 0)
        {
            node_array[i].last = &node_array[i - 1];
        }
        node_array[i].index = i + 1;
        if (i != 12)
        {
            node_array[i].next = &node_array[i + 1];
        }
    }
    node_array[0].last = &node_array[12];
    node_array[12].next = &node_array[0];
    int current_size = 13;
    int count = 1;
    struct Node *current_node = node_array;
    while (current_node != current_node->next)
    {
        
        if(count == 3){
            count = 0;
            current_node->last->next = current_node->next;
            current_node->next->last = current_node->last;
            current_size--;
        }
        count++;
        current_node = current_node->next;
    }
    printf("%d", current_node->index);
}