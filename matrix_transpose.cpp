#include <iostream>
#include <iomanip>
using namespace std;

struct matrix
{
    int row;
    int column;
    int value;
};

void showMatrix(matrix *a)
{
    cout << "Matrix:\n==========================\n";
    int x = a[0].row;
    int y = a[0].column;
    int **arr = new int *[x];
    for (int i = 0; i < x; i++)
        arr[i] = new int[y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i <= a[0].value; i++)
    {
        arr[a[i].row][a[i].column] = a[i].value;
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "==========================\n";
}

matrix *transpose(matrix *a)
{
    int n = a[0].value;
    int rowTerm[n] = {0};
    for (int i = 1; i <= n; i++)
        rowTerm[a[i].column]++;

    int startPos[n];
    startPos[0] = 1;
    for (int i = 1; i < n; i++)
        startPos[i] = startPos[i - 1] + rowTerm[i - 1];

    matrix *b = new matrix[n + 1];
    b[0].row = a[0].column;
    b[0].column = a[0].row;
    b[0].value = a[0].value;
    for (int i = 1; i <= n; i++)
    {
        int j = startPos[a[i].column]++;
        b[j].column = a[i].row;
        b[j].row = a[i].column;
        b[j].value = a[i].value;
    }
    return b;
}

int main()
{
    int x, y, v;
    cin >> x >> y >> v;
    matrix a[v + 1];
    a[0].row = x;
    a[0].column = y;
    a[0].value = v;
    for (int i = 1; i <= a[0].value; i++)
    {
        cin >> x >> y >> v;
        a[i].row = x;
        a[i].column = y;
        a[i].value = v;
    }
    showMatrix(a);
    showMatrix(transpose(a));
}