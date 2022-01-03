#include <iostream> 
#include <deque>
#include <algorithm>
using namespace std;

void push_middle(deque<int>& frontQ, deque<int>& backQ) {
    int idx = (frontQ.size() + backQ.size() + 1) / 2;
    while (frontQ.size() < idx) {
        frontQ.push_back(backQ.front());
        backQ.pop_front();
    }
    while (frontQ.size() > idx) {
        backQ.push_front(frontQ.back());
        frontQ.pop_back();
    }
}

int main() {
    //freopen("1.in","r",stdin);
    int n; cin >> n;
    deque<int> frontQ;
    deque<int> backQ;
    for (int i=0; i<n; i++) {
        string command; int v; cin >> command >> v;
        if (command == "push_front") 
            frontQ.push_front(v);
        if (command == "push_back")
            backQ.push_back(v);
        if (command == "push_middle") {
            push_middle(frontQ, backQ);
            frontQ.push_back(v);
        }
        if (command == "get") {
            if (v >= frontQ.size()) {
                v -= frontQ.size();
                cout << backQ[v] << '\n';
            } else {
                cout << frontQ[v] << '\n';
            }          
        }
    }
}