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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

unordered_map<int, vi> M;
unordered_map<int, int> V;
unordered_map<int, int> T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m; cin >> n >> m;
    while (m--) {
        int a,b;
        cin >> a >> b;
        M[a].emplace_back(b);
        M[b].emplace_back(a);
    }
    for (int i=1; i<=n; i++) {
        cin >> m;
        V[i] = m;
        T[i] = 0;
    }

    priority_queue<ii, vii, greater<ii>> Q;
    Q.emplace(0,1);
    int total = V[1];
    T[1] = 1;

    while (!Q.empty()) {
        int u = Q.top().second;
        int w = Q.top().first;
        Q.pop();

        if (total <= w) break;
        total += w;

        for (auto& v:M[u]) {
            if (T[v]) continue;
            T[v] = 1;
            Q.emplace(V[v], v);
        }
    }
    cout << total;
}