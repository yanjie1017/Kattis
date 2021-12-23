#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

unordered_map<char, char> M = {
    {'}','{'},
    {']','['},
    {')','('},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n; cin.get();
    string input;
    getline(cin, input);

    stack<char> S; 
    for (int i=0; i<input.length(); i++) {
        char x = input[i];
        if (x == '{' ||
            x == '[' ||
            x == '(') {
                S.push(x);
        }
        if (x == '}' ||
            x == ']' ||
            x == ')') {
            if (S.empty() || S.top() != M[x]) {
                cout << x << ' ' << i;
                return 0;
            } else {
                S.pop();
            }
        }
    }
    cout << "ok so far";
}
