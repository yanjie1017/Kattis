#include <iostream>
#include <sstream>
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
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n; int step = 0;
    stack<ll> s1;
    stack<ll> s2;
    for (int i=0; i<2*n; i++) {
        int x; cin >> x; s1.push(x);
    }
    while (!s1.empty()) {
        if (!s2.empty() && s1.top() == s2.top()) {
            s1.pop(); s2.pop();
        } else {
            s2.push(s1.top()); 
            s1.pop();
        }
        step++;
    }
    if (s2.empty()) cout << step;
    else cout << "impossible";
}
