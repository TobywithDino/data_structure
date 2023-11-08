#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void push(node **top, int data)
{
    node *n = new node{data, nullptr};
    n->next = *top;
    *top = n;
}

void pop(node **top)
{
    node *n = *top;
    if ((*top)->next == nullptr)
        *top = nullptr;
    else
        *top = (*top)->next;
    delete n;
}

int main()
{
    node *stack = new node;
    push(&stack, 3);
    push(&stack, 5);
    cout << stack->data << endl;
    pop(&stack);
    cout << stack->data << endl;
    pop(&stack);
}