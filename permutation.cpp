#include <iostream>
#include <cstring>
using namespace std;

void permutation_recursive(char* list, int i, int n){
    if(i==n){
        for(int j=0;j<n;j++){
            cout << list[j];
        }
        cout << endl;
    }else{
        for(int j=i;j<n;j++){
            swap(list[i],list[j]);
            permutation_recursive(list, i+1, n);
            swap(list[i],list[j]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    char *list = new char[n];
    string tmp;
    cin >> tmp;
    strcpy(list, tmp.c_str());
    cout << "=================\n";
    permutation_recursive(list, 0, n);
    cout << "=================\n";
}