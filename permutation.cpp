#include <iostream>
#include <cstring>
using namespace std;

void permutation(char *list, int i, int n)
{
    if (i == n)
    {
        printf("%s\n", list);
    }
    else
    {
        for (int j = i; j < n; j++)
        {
            swap(list[i], list[j]);
            permutation(list, i + 1, n);
            swap(list[i], list[j]);
        }
    }
}

int main()
{
    char list[100];
    string s;
    cin >> s;
    strcpy(list, s.c_str());
    permutation(list, 0, s.length());
}