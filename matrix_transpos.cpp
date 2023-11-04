#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int m,n;
    cin >> m >> n;
    int *arr;
    arr = new int[m];
    for(int i=0;i<m;i++) arr[i] = 0;
    int a,b;
    for(int i=0;i<x;i++){
        cin >> a >> b;
        arr[a-1]++;
    }
    int startPos = 1;
    cout << startPos;
    for(int i=0;i<m-1;i++){
        startPos+=arr[i];
        cout << " " << startPos;
    }
    cout << endl;
    delete[] arr;
}