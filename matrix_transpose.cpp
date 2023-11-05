#include <iostream>
using namespace std;

struct matrix{
    int row;
    int column;
    matrix* next;
};

void insert(matrix* m, int row, int column){
    matrix* tmp;
    tmp = m;

    matrix* node = new matrix{row, column, nullptr};
    while(m->next != nullptr){
        m = m->next;
    }
    m->next = node;

    m = tmp;
}

void initializeMatrix(matrix* m){
    int row = m->row;
    int column = m->column;
    
}

int main(){
    matrix *a = new matrix{6,6,nullptr};
}