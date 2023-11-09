#include <iostream>
using namespace std;

typedef struct node *nodePtr;
struct node
{
    int data;
    nodePtr link;
};

void insert(nodePtr *ptr, int pos, int data)
{
    nodePtr tmp = new node;
    tmp->link = *ptr;

    if (!tmp->link)
    {
        if (pos != 0)
        {
            printf("Out of index\n");
            return;
        }
        *ptr = new node{data, nullptr};
        return;
    }
    for (int i = 1; i <= pos; i++)
    {
        if (tmp->link)
        {
            tmp = tmp->link;
        }
        else
        {
            printf("Out of index\n");
            break;
        }
    }
    nodePtr n = new node{data, tmp->link};
    tmp->link = n;
    if (pos == 0)
        *ptr = tmp->link;
}

void pop(nodePtr *ptr, int pos)
{
    nodePtr tmp = new node;
    tmp->link = *ptr;
    for (int i = 1; i <= pos; i++)
    {
        tmp = tmp->link;
    }
    nodePtr n = tmp->link;
    tmp->link = tmp->link->link;
    delete n;
}

void showList(nodePtr ptr)
{
    while (ptr != nullptr)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

void invert(nodePtr *ptr)
{
    nodePtr lead = *ptr;
    nodePtr middle = new node;
    nodePtr trail = new node;
    middle = nullptr;
    while (lead)
    {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    *ptr = middle;
}

int main()
{
    nodePtr ptr = new node;
    ptr = nullptr;
    insert(&ptr, 0, 3);
    insert(&ptr, 1, 5);
    insert(&ptr, 1, 7);
    insert(&ptr, 3, 8);
    insert(&ptr, 0, 1);
    pop(&ptr, 2);
    showList(ptr);
    invert(&ptr);
    showList(ptr);
}