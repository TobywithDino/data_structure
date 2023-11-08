#include <iostream>
using namespace std;

struct node
{
    int coef;
    int degree;
    node *next;
};

void insert(node *ptr, int coef, int degree)
{
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    node *tmp = new node{coef, degree, nullptr};
    ptr->next = tmp;
}

node *combine(node *a, node *b)
{
    node *head = new node;
    node *cur = new node;
    head = cur;
    while (a != nullptr && b != nullptr)
    {
        node *tmp = new node;
        tmp->next = nullptr;
        cur->next = tmp;
        if (a->degree > b->degree)
        {
            tmp->degree = a->degree;
            tmp->coef = a->coef;
            a = a->next;
        }
        else if (a->degree < b->degree)
        {
            tmp->degree = b->degree;
            tmp->coef = b->coef;
            b = b->next;
        }
        else
        {
            tmp->degree = a->degree;
            tmp->coef = a->coef + b->coef;
            a = a->next;
            b = b->next;
        }
        cur = cur->next;
    }

    while (a != nullptr)
    {
        insert(head, a->coef, a->degree);
        a = a->next;
    }
    while (b != nullptr)
    {
        insert(head, b->coef, b->degree);
        b = b->next;
    }

    return head->next;
}

int main()
{
    node *a = new node{13, 10, nullptr};
    insert(a, 32, 9);
    insert(a, 71, 8);
    insert(a, 50, 6);
    insert(a, 2, 4);
    insert(a, 3, 3);
    insert(a, 20, 2);
    insert(a, 7, 1);
    insert(a, 21, 0);

    node *b = new node{3, 9, nullptr};
    insert(b, 13, 8);
    insert(b, -3, 6);
    insert(b, 20, 4);

    node *result = combine(a, b);
    while (result != nullptr)
    {
        cout << result->coef << "X^" << result->degree << endl;
        result = result->next;
    }
}