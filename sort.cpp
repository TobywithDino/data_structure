#include <iostream>
#include <algorithm>
using namespace std;

void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
    }
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    sort(arr, arr + n, cmp);
    show(arr, n);
}