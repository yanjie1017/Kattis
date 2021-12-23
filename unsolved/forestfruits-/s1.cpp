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
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

vector<vector<ii>> AL;
unordered_set<ll> dest;
vector<ll> step;
priority_queue<ll> ans;
ll V, E, C, K, M;
ll reached;

int bfs() {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    step[0] = 0; 
    q.emplace(0, 0);
    while (!q.empty()) {
        ll u = q.top().second; ll w = q.top().first; q.pop();
        // if (reached == C) return 0;
        if (dest.find(u) != dest.end()) {
            ans.push(w);
            reached++;
        }

        for (auto& x:AL[u]) {
            int v = x.second; 
            int next_w = x.first + w;
            if (next_w < step[v]) {
                step[v] = next_w;
                q.emplace(next_w,v);
            }
        } 
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> V >> E >> C >> K >> M;
    AL.assign(V, vector<ii>());
    step.assign(V, INT_MAX);

    for (int i=0; i<E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u-1].emplace_back(w,v-1);
        AL[v-1].emplace_back(w,u-1);
    }
    
    for (int i=0; i<C; i++) {
        int x; cin >> x;
        dest.insert(x-1);
    }

    if (M > C && C < K) {
        cout << -1;
        return 0;
    }

    reached = 0;
    bfs();
    if (M > reached && reached < K) {
        cout << -1;
        return 0;
    } 
    ll m = ans.size() - min(M, K);
    while (m--) {
        ans.pop();
    }
    cout << ans.top()*2;
    return 0;
}