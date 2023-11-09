#include <iostream>
using namespace std;

typedef struct node *nodePtr;
struct node
{
    int data;
    nodePtr next;
};

void push(nodePtr *front, nodePtr *rear, int data)
{
    nodePtr newNode = new node{data, nullptr};
    if (*front)
        (*rear)->next = newNode;
    else
        *front = newNode;
    (*rear) = newNode;
}

void pop(nodePtr *front, nodePtr *rear)
{
    if (!front)
    {
        printf("Empty\n");
        return;
    }
    nodePtr tmp = *front;
    *front = (*front)->next;
    delete tmp;
}

int main()
{
    nodePtr front = new node;
    front = nullptr;
    nodePtr rear = new node;
    rear = nullptr;
    push(&front, &rear, 3);
    push(&front, &rear, 5);
    push(&front, &rear, 7);
    pop(&front, &rear);
    printf("%d\n", front->data);
}