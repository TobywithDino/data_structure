#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> icp = {
    {'(', 20},
    {')', 19},
    {'+', 12},
    {'-', 12},
    {'*', 13},
    {'/', 13},
    {'%', 13}
};

map<char, int> isp = {
    {'(', 0},
    {')', 19},
    {'+', 12},
    {'-', 12},
    {'*', 13},
    {'/', 13},
    {'%', 13}
};

int main(){
    char infix[100];
    scanf("%s",infix);

    char postfix[100];
    stack<char> st;
    int i = 0, k = 0;
    while(infix[i] != '\0'){
        if(icp[infix[i]] == 0)                      // if it is operand instead of operator, add the operand to the postfix. 
        {
            postfix[k] = infix[i];
            k++;
        }
        else if(st.empty())                         // if stack is empty, push it with the operator.
        {
            st.push(infix[i]);
        }
        else if(infix[i] == ')')                    // if incoming operator is ')', pop the stack until it reaches '('
        {
            while(st.top()!='(')
            {
                postfix[k] = st.top();
                st.pop();
                k++;            
            }
            st.pop();
        }
        else if(isp[st.top()] < icp[infix[i]])      // if incoming operator has greater priority than the top of stack, push if into stack
        {
            st.push(infix[i]);
        }
        else
        {
            while(isp[st.top()] >= icp[infix[i]]){  // if not greater(lower or equal to), pop the stack and check again until it's greater than the top of stack
                postfix[k] = st.top();
                k++;
                st.pop();
                if(st.empty()) break;
            }
            st.push(infix[i]);
        }
        i++;
    }

                                                    
    while(!st.empty()){                             // clear remains of stack into postfix
        postfix[k] = st.top();
        st.pop();
        k++;
    }
    postfix[k] = '\0';
    printf("%s\n", postfix);
}