#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <climits>
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
    vector<int> v(n);
    for (auto& x:v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    map<int, stack<int>> M;
    M[v[0]] = stack<int>();
    for (int i=1; i<v.size(); i++) {
        int prev = v[i-1];
        while (v[i] - v[i-1] == 1) {
            M[prev].push(v[i]);
            i++;
        }
        if (i<v.size()) M[v[i]] = stack<int>();
    }

    for (auto const& x:M) {
        if (x.second.size() == 0) cout << x.first << ' ';
        else if (x.second.size() == 1) cout << x.first << ' ' << x.second.top() << ' ';
        else cout << x.first << '-' << x.second.top() << ' ';
    }
}