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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    stack<int> s1; stack<int> s2;
    while (n--) {
        int x; cin >> x; s1.push(x);
    } 
    while (!s1.empty()) {
        s2.push(s1.top()); s1.pop();
        while (!s1.empty() & !s2.empty()
        && ((s1.top() + s2.top()) % 2 == 0)) {
            s1.pop();
            s2.pop();
        }
    }
    cout << s2.size();
}