#include <iostream>
using namespace std;

typedef struct node *nodePtr;
struct node
{
    int coef;
    int degree;
    nodePtr link;
};

void push(nodePtr *ptr, int coef, int degree)
{
    nodePtr n = new node{coef, degree, nullptr};
    if (!(*ptr))
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
    while (true)
    {
        if (ptr->degree == 0)
        {
            printf("%d", ptr->coef);
        }
        else if (ptr->degree == 1)
        {
            printf("%dx", ptr->coef);
        }
        else
        {
            printf("%dx^%d", ptr->coef, ptr->degree);
        }
        if (ptr->link)
        {
            ptr = ptr->link;
            if (ptr->coef > 0)
                printf("+");
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

nodePtr add(nodePtr a, nodePtr b)
{
    nodePtr c = new node;
    c = nullptr;
    while (a && b)
    {
        if (a->degree == b->degree)
        {
            int t = a->coef + b->coef;
            if (t != 0)
                push(&c, t, a->degree);
            a = a->link;
            b = b->link;
        }
        else if (a->degree < b->degree)
        {
            push(&c, b->coef, b->degree);
            b = b->link;
        }
        else if (a->degree > b->degree)
        {
            push(&c, a->coef, a->degree);
            a = a->link;
        }
    }
    while (a)
    {
        push(&c, a->coef, a->degree);
        a = a->link;
    }
    while (b)
    {
        push(&c, b->coef, b->degree);
        b = b->link;
    }
    return c;
}

int main()
{
    nodePtr a = new node;
    a = nullptr;
    nodePtr b = new node;
    b = nullptr;

    int n1;
    cin >> n1;
    int coef, deg;
    for (int i = 0; i < n1; i++)
    {
        cin >> coef >> deg;
        push(&a, coef, deg);
    }
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> coef >> deg;
        push(&b, coef, deg);
    }
    nodePtr c = add(a, b);
    show(a);
    show(b);
    show(c);
}