#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m + 2][n + 2];
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            int x;
            if (i == 0 || i == m + 1 || j == 0 || j == n + 1)
                x = 1;
            else
                cin >> x;
            arr[i][j] = x;
        }
    }
    stack<pair<int, int>> path;
    path.push({1, 1});
    arr[1][1] = 1;
    bool hasEntry = true;
    while (path.top() != pair<int, int>(m, n))
    {
        pair<int, int> head = path.top();
        pair<int, int> dir[4] = {
            {head.first - 1, head.second},
            {head.first, head.second - 1},
            {head.first + 1, head.second},
            {head.first, head.second + 1}};
        if (arr[dir[0].first][dir[0].second] == 0)
        {
            path.push(dir[0]);
            arr[dir[0].first][dir[0].second] = 1;
        }
        else if (arr[dir[1].first][dir[1].second] == 0)
        {
            path.push(dir[1]);
            arr[dir[1].first][dir[1].second] = 1;
        }
        else if (arr[dir[2].first][dir[2].second] == 0)
        {
            path.push(dir[2]);
            arr[dir[2].first][dir[2].second] = 1;
        }
        else if (arr[dir[3].first][dir[3].second] == 0)
        {
            path.push(dir[3]);
            arr[dir[3].first][dir[3].second] = 1;
        }
        else
        {
            path.pop();
            if (path.empty())
            {
                hasEntry = false;
                break;
            }
        }
    }
    if (!hasEntry)
    {
        printf("No Exit\n");
    }
    else
    {
        stack<pair<int, int>> ans;
        while (!path.empty())
        {
            ans.push(path.top());
            path.pop();
        }
        while (!ans.empty())
        {
            printf("(%d,%d) ", ans.top().first - 1, ans.top().second - 1);
            ans.pop();
        }
    }
}