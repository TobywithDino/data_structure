#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int **arr;
    arr = new int*[h+2];
    for(int i=0;i<h+2;i++) arr[i] = new int[w+2];
    int t;
    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            cin >> t;
            arr[i][j] = t;
        }
    }
    for(int i=0;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            if(i==0 || i==h+1 || j==0 || j==w+1) arr[i][j] = 1;
        }
    }
    bool exit = true;
    stack<pair<int,int>> path;
    path.push({1,1});
    arr[1][1] = 1;
    while(path.top() != pair<int,int>(h,w)){
        pair<int,int> head = path.top();
        pair<int,int> dir[4] ={
            {head.first+1,head.second},
            {head.first,head.second+1},
            {head.first-1,head.second},
            {head.first,head.second-1}
        };
        if(arr[dir[0].first][dir[0].second] == 0){
            path.push(dir[0]);
            arr[dir[0].first][dir[0].second] = 1;
        }else if(arr[dir[1].first][dir[1].second] == 0){
            path.push(dir[1]);
            arr[dir[1].first][dir[1].second] = 1;
        }else if(arr[dir[2].first][dir[2].second] == 0){
            path.push(dir[2]);
            arr[dir[2].first][dir[2].second] = 1;
        }else if(arr[dir[3].first][dir[3].second] == 0){
            path.push(dir[3]);
            arr[dir[3].first][dir[3].second] = 1;
        }else{
            path.pop();
            if(path.empty()){
                exit = false;
                cout << "Can't reach the exit\n";
                break;
            }
        }
    }

    if(!exit) return 0;
    stack<pair<int,int>> ans;
    while(!path.empty()){
        ans.push(path.top());
        path.pop();
    }
    cout << "(" << ans.top().first-1 << "," << ans.top().second-1 << ")";
    ans.pop();
    while(!ans.empty()){
        cout << " " << "(" << ans.top().first-1 << "," << ans.top().second-1 << ")";
        ans.pop();
    }

    for(int i=0;i<h+2;i++) delete[] arr[i];
    delete[] arr;
}