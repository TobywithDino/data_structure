#include <iostream>
#include <cstring>
using namespace std;

void permutation(char* list, int i, int n){
    if(i==n)
    {
        printf("%s\n", list);
    }
    else
    {
        for(int j=i;j<n;j++){
            swap(list[i],list[j]);
            permutation(list,i+1,n);
            swap(list[i],list[j]);
        }
    }
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    char* list = new char[n];
    strcpy(list, s.c_str());
    permutation(list, 0, n);
}