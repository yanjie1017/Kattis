#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

void balance(priority_queue<int>& left, priority_queue<int, vector<int>, greater<int>>& right) {
    if (left.empty() && right.empty()) return;
    if (left.empty() && right.size() == 1) return;
    if (right.size() < left.size()) {
        right.push(left.top());
        left.pop();
    }
    int ll = left.top();
    int rr = right.top();
    if (rr < ll) {
        left.pop(); right.pop();
        left.push(rr); right.push(ll);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("cookie.in","r",stdin);
    string s;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    while (cin >> s) {
        if (s == "#") {
            cout << right.top() << '\n';
            right.pop();
        } else {
            left.push(stoi(s));
        }
        balance(left, right);
    }
    return 0;
}