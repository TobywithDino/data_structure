#include <stdlib.h>
#include <stdio.h>

typedef struct node *nodePtr;
struct node
{
    int data;
    nodePtr link;
};

void push(nodePtr *ptr, int data)
{
    nodePtr n = (nodePtr)malloc(sizeof(nodePtr));
    n->data = data;
    n->link = NULL;
    if (!*ptr)
    {
        *ptr = n;
        return;
    }
    nodePtr tmp = *ptr;
    while (tmp->link)
    {
        tmp = tmp->link;
    }
    tmp->link = n;
}

void show(nodePtr ptr)
{
    while (ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    nodePtr ptr = (nodePtr)malloc(sizeof(nodePtr));
    ptr = NULL;
    push(&ptr, 3);
    push(&ptr, 4);
    push(&ptr, 5);
    show(ptr);
}
