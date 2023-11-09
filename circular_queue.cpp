#include <iostream>
using namespace std;

int front = 0;
int rear = 0;
int MAX_QUEUE = 10;
void push(int *q, int data);
int pop(int *q);
int main()
{
}

void push(int *q, int data)
{
    rear = (rear + 1) % MAX_QUEUE;
    if (front == rear)
    {
        printf("Full\n");
        return;
    }
    q[rear] = data;
}

int pop(int *q)
{
    if (front == rear)
        printf("Empty\n");
    front = (front + 1) % MAX_QUEUE;
    return q[front];
}