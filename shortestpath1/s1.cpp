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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

vector<vector<ii>> AL;
vector<ll> weight;


void bfs(ll s) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    weight[s] = 0;
    q.emplace(0,s);
    while (!q.empty()) {
        ll u = q.top().second; ll w = q.top().first; q.pop();
        for (auto& v:AL[u]) {
            ll curr_w = v.first + w;
            if (weight[v.second] > curr_w) {
                weight[v.second] = curr_w;
                q.emplace(curr_w, v.second);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    
    ll n, m, q, s;
    while (cin >> n) {
        cin >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) return 0;

        AL.assign(n, vector<ii>());
        weight.assign(n, INT_MAX);

        for (int i=0; i<m; i++) {
            int u, v, w; cin >> u >> v >> w;
            AL[u].emplace_back(w,v);
        }

        bfs(s);

        for (int i=0; i<q; i++) {
            int x; cin >> x;
            if (weight[x] == INT_MAX) cout << "Impossible";
            else cout << weight[x];
            cout << '\n';
        }
        AL.clear();
        weight.clear();
        cout << '\n';
    }
}