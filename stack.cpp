#include <iostream>
using namespace std;

void push(int *stack, int item);
int pop(int *stack);

int top = -1;
int main()
{
    int *stack = new int[100];
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    printf("%d\n", stack[top]);
    int a = pop(stack);
    printf("%d\n", a);
    printf("%d\n", stack[top]);
}

void push(int *stack, int item)
{
    stack[++top] = item;
}

int pop(int *stack)
{
    if (top == -1)
    {
        printf("Empty\n");
        return 0;
    }
    return stack[top--];
}