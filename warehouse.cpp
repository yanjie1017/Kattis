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

bool compare(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m; cin >> n;
    while (n--) {
        cin >> m;
        unordered_map<string, int> M;
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&compare)> q(compare);

        while (m--) {
            string s; int x; cin >> s >> x;
            M[s] += x;
        }

        for (auto& x:M) {
            q.emplace(x.second, x.first);
        }

        cout << q.size() << '\n';
        while (!q.empty()) {
            cout << q.top().second << ' ' << q.top().first << '\n';
            q.pop();
        }

    }
      
}