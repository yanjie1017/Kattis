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

vector<int> visited;
vector<vi> AL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m, u, v; cin >> n >> m;
    AL.assign(n+1, vi());
    visited.assign(n+1,0);

    while (m--) {
        cin >> u >> v;
        AL[u].emplace_back(v);
        AL[v].emplace_back(u);
    }

    queue<int> Q;
    Q.push(1); visited[1] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto& v:AL[u]) {
            if (visited[v]) continue;
            visited[v] = 1;
            Q.push(v);
        }
    }

    bool isConnected = true;
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;
        cout << i << endl; 
        isConnected = false;
    }

    if (isConnected) cout << "Connected";
}
