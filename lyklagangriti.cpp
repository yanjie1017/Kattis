#include <iostream> 
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string input; cin >> input;
    std::stack<char> befStack;
    std::stack<char> aftStack;
    for (auto& x:input) {
        switch (x)
        {
        case 'L':
            aftStack.push(befStack.top());
            befStack.pop();
            break;
        case 'R':
            befStack.push(aftStack.top());
            aftStack.pop();
            break;
        case 'B':
            befStack.pop();
            break;
        default:
            befStack.push(x);
            break;
        }
    }
    while (!befStack.empty()) {
        aftStack.push(befStack.top());
        befStack.pop();
    }
    while (!aftStack.empty()) {
        cout << aftStack.top();
        aftStack.pop();
    }
}