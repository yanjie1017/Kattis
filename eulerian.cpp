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
#include <utility>
using namespace std;

using ll = long long;
using ii = pair<ll,ll>;

unordered_map<ll, vector<ll>> IN;
unordered_map<ll, vector<ll>> OUT;
vector<ll> visited; 

unordered_set<ll> bfs(int i) {
    queue<ll> q;
    unordered_set<ll> s;
    visited[i] = 1; q.push(i); s.insert(i);

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto& v:IN[u]) {
            if (visited[v]) continue;
            visited[v] = 1; 
            q.push(v);
            s.insert(v);
        }  
        for (auto& v:OUT[u]) {
            if (visited[v]) continue;
            visited[v] = 1; 
            q.push(v);
            s.insert(v);
        }     
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n,m; cin >> n >> m;

    if (m==0) {
        cout << "anywhere"; return 0;
    }
    
    while (m--) {
        ll u,v; cin >> u >> v;
        IN[v].push_back(u);
        OUT[u].push_back(v);
    }

    bool isConnected = true;
    int cc = 0; visited.assign(n+1,0);
    for (ll i=1; i<=n; i++) {
        if (visited[i]) continue;
        unordered_set<ll> s = bfs(i); cc++;
        if (cc > 1) {
            if (s.size() > 1) isConnected = false;
            else {
                ll x = *s.begin(); 
                if (!IN[x].empty() || !OUT[x].empty()) isConnected = false;
            }
        }
    }

    bool hasCircuit = true;
    bool hasPath = true;
    ll start = 0; ll end = 0; 
    ll startc = 0; ll endc = 0;
    for (ll i=1; i<=n; i++) {
        if (abs((int)IN[i].size() - (int)OUT[i].size()) > 1) {
            hasPath = false; break;
        }
        if ((int)OUT[i].size() - (int)IN[i].size() == 1) {
            hasCircuit = false;
            start = i;
            startc++; 
        } 
        if ((int)IN[i].size() - (int)OUT[i].size() == 1) {
            hasCircuit = false;
            end = i;
            endc++; 
        } 
    }

    if (!isConnected) {
        cout << "no"; return 0;
    }
    if (!hasPath) {
        cout << "no"; return 0;
    }
    if (hasCircuit) {
        cout << "anywhere"; return 0;
    } else {
        if (startc == 1 && endc == 1) {
            cout << start << " " << end; return 0;
        }
        cout << "no"; return 0;
    }
}