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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;

unordered_map<int, vector<int>> AL;
vector<int> visited;
stack<int> tps;
bool isCycle = false;

void cycle(int i) {
    visited[i] = 1;
    for (auto& x:AL[i]) {
        if (!visited[x]) cycle(x);
        if (visited[x] == 1) isCycle = true;
    } 
    visited[i] = 2;
    tps.push(i); 
}

// void dfs(int s) {
//     if (visited[s]) return;
//     visited[s] = 1;
//     for (auto& x : AL[s]) {
//         if (!visited[x]) dfs(x);
//     }
//     tps.push(s); 
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n,m,a,b; cin >> n >> m;
    visited.assign(n+1, 0);

    while (m--) {
        cin >> a >> b;
        AL[a].push_back(b);
    }
    
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;
        cycle(i);
        if (isCycle) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    while (!tps.empty()) {
        cout << tps.top() << endl; tps.pop();
    }
}