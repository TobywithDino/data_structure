#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int* arr, int x, int l, int r){
    if(l>r) return -1;
    int middle = (l+r)/2;
    if(arr[middle] == x) return middle;
    else if(arr[middle] > x) return binary_search(arr,x,l,middle-1);
    else return binary_search(arr,x,middle+1,r);
}


int main(){
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        arr[i] = temp; 
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    int x;
    cin >> x;
    cout << binary_search(arr, x, 0, n-1) << endl;
    delete[] arr;
}