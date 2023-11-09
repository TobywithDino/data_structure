#include <iostream>
#include <algorithm>
#include <vector>
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

void del(nodePtr *ptr, int pos)
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

void push(nodePtr *ptr, int data)
{
    if (!*ptr)
    {
        *ptr = new node{data, nullptr};
        return;
    }
    nodePtr tmp = *ptr;
    while (tmp->link)
    {
        tmp = tmp->link;
    }
    tmp->link = new node{data, nullptr};
}

void pop(nodePtr *ptr)
{
    nodePtr tmp = new node;
    tmp->link = *ptr;
    while (tmp->link->link)
    {
        tmp = tmp->link;
    }
    nodePtr n = tmp->link;
    tmp->link = nullptr;
    delete n;
}

void showList(nodePtr ptr)
{
    printf("=========\n");
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

bool compareNode(nodePtr a, nodePtr b)
{
    int aData = a->data;
    int bData = b->data;
    return a > b;
}

void sortList_vector(nodePtr *ptr)
{
    vector<nodePtr> v;
    while (*ptr)
    {
        v.push_back(*ptr);
        *ptr = (*ptr)->link;
    }
    sort(v.begin(), v.end(), compareNode);
    for (int i = 0; i < v.size(); i++)
    {
        push(ptr, v[i]->data);
    }
}

void sortList_bubble(nodePtr *ptr)
{
    nodePtr i = *ptr;
    nodePtr j = i;
    while (i)
    {
        while (j)
        {
            if (i->data < j->data)
            {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
            j = j->link;
        }
        i = i->link;
        j = i;
    }
}

void sortList_selection(nodePtr *ptr)
{
    nodePtr i = *ptr;
    nodePtr j = i;
    while (i)
    {
        nodePtr max = i;
        while (j)
        {
            if (max->data < j->data)
            {
                max = j;
            }
            j = j->link;
        }
        int tmp = i->data;
        i->data = max->data;
        max->data = tmp;
        i = i->link;
        j = i;
    }
}

void sortList_insertion(nodePtr *ptr)
{
}

int main()
{
    nodePtr ptr = new node;
    ptr = nullptr;
    // insert(&ptr, 0, 3);
    // insert(&ptr, 1, 5);
    // insert(&ptr, 1, 7);
    // insert(&ptr, 3, 8);
    // insert(&ptr, 0, 1);
    // del(&ptr, 2);
    // showList(ptr);
    // invert(&ptr);
    // showList(ptr);

    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        push(&ptr, tmp);
    }
    showList(ptr);
    // sortList_vector(&ptr);
    // sortList_bubble(&ptr);
    // sortList_selection(&ptr);
    // sortList_insertion(&ptr);
    showList(ptr);
}