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

    int n, m; cin >> n >> m;
    stack<int> s;

    while (m--) {
        string x; cin >> x;
        if (x == "undo") {
            int cnt; cin >> cnt;
            while (cnt--) {
                s.pop();
            }
            continue;
        }
        s.push(stoi(x));
    }

    int total =0;
    while (!s.empty()) {
        total += s.top(); s.pop();
    }

    while (total < 0) {
        total += n;
    }
    cout << total % n;   
}
