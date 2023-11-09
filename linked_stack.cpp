#include <iostream>
using namespace std;

typedef struct node *nodePtr;
struct node
{
    int data;
    nodePtr next;
};

void push(nodePtr *top, int data)
{
    nodePtr n = new node{data, *top};
    *top = n;
}

void pop(nodePtr *top)
{
    nodePtr n = *top;
    if ((*top)->next == nullptr)
        *top = nullptr;
    else
        *top = (*top)->next;

    delete n;
}

int main()
{
    nodePtr top = new node;
    top = nullptr;
    push(&top, 3);
    push(&top, 5);
    cout << top->data << endl;
    pop(&top);
    cout << top->data << endl;
    pop(&top);
}