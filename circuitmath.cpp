#include <iostream> 
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;

char or_func(char a, char b) {
    if (a == 'F' && b == 'F') {
        return 'F';
    }
    return 'T';
}
char and_func(char a, char b) {
    if (a == 'T' && b == 'T') {
        return 'T';
    }
    return 'F';
}
char not_func(char a) {
    if (a == 'F') {
        return 'T';
    }
    return 'F';
}

int main() {
    int n; cin >> n;
    char value[n];
    for (int i=0; i<n;i++) {
        cin >> value[i]; 
    }
    char wc = cin.get();
    string input;
    getline(cin, input);

    stack<char> stack1;
    int counter = 0;
    char x, y;
    
    for (int i=0; i<input.length(); i++) {
        char M = input[i];
        switch (M) {
            case ' ':
                break;
            case '+':
                x = stack1.top(); stack1.pop();
                y = stack1.top(); stack1.pop();
                stack1.push(or_func(x,y));
                break;
            case '-':
                x = stack1.top();
                stack1.pop();
                stack1.push(not_func(x));
                break;
            case '*':
                x = stack1.top(); stack1.pop();
                y = stack1.top(); stack1.pop();
                stack1.push(and_func(x,y));
                break;
            default:
                stack1.push(value[counter++]);
                break;
        }
    }
    cout << stack1.top();
    return 0;
}