#include <iostream>
using namespace std;

int front = -1;
int rear = -1;
void push(int *q, int data);
int pop(int *q);
int main()
{
    int *queue = new int[100];
    push(queue, 3);
    push(queue, 4);
    push(queue, 5);
    push(queue, 6);
    push(queue, 7);
    printf("%d\n", queue[rear]);
    int a = pop(queue);
    printf("%d\n", a);
    printf("%d\n", queue[rear]);
}

void push(int *q, int data)
{
    q[++rear] = data;
}
int pop(int *q)
{
    if (front == rear)
    {
        printf("Empty\n");
        return 0;
    }
    return q[++front];
}