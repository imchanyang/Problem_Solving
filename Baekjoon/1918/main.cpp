#include <iostream>
#include <stack>
using namespace std;

int main() {
    string statement;
    cin >> statement;

    stack<char> oper;

    for(int i = 0; i < statement.length(); i++) {
        if('A' <= statement[i] && statement[i] <= 'Z') {
            cout << statement[i];
        }
        else if(statement[i] == '(') {
            oper.push(statement[i]);
        }
        else if(statement[i] == ')') {
            while(oper.top() != '(') {
                cout << oper.top();
                oper.pop();
            }
            oper.pop();
        }
        else if(statement[i] == '*' || statement[i] == '/') {
            while(!oper.empty() && (oper.top() == '*' || oper.top() == '/')) {
                cout << oper.top();
                oper.pop();
            }
            oper.push(statement[i]);
        }
        else if(statement[i] == '+' || statement[i] == '-') {
            while (!oper.empty() && oper.top() != '(') {
                cout << oper.top();
                oper.pop();
            }
            oper.push(statement[i]);
        }
    }

    while(!oper.empty()) {
        cout << oper.top();
        oper.pop();
    }
    cout << endl;

    return 0;
}