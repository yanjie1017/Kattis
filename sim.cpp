#include <iostream> 
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    cin.ignore();
    for (int i=0; i<n; i++) {
        string input; getline(cin, input);
        list<char> frontQ; 
        list<char> backQ; 
        int pointer = 0;
        for (auto& x:input) {
            switch (x)
            {
            case '[':
                backQ.splice(backQ.begin(), frontQ);
                frontQ = {};
                pointer = 0;
                break;
            case ']':
                backQ.splice(backQ.begin(), frontQ);
                frontQ = {};
                pointer = 1;
                break;
            case '<':
                if (pointer == 0) {
                    if (!frontQ.empty()) 
                        frontQ.pop_back(); 
                } else {
                    if (!backQ.empty()) 
                        backQ.pop_back();
                }
                break;
            default:
                if (pointer == 0)
                    frontQ.push_back(x);
                else
                    backQ.push_back(x);
                break;
            }
        }
        backQ.splice(backQ.begin(), frontQ);
        frontQ = {};
        while (!backQ.empty()) {
            cout << backQ.front();
            backQ.pop_front();
        }
        cout << '\n';
    }
}