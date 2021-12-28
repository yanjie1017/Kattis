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

vector<int> V;
vector<int> visited;
vector<vi> AL; 

int bfs(int i) {
    queue<int> q;
    q.push(i); visited[i] = 1;
    int total = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        total += V[u]; 
        for (auto& x:AL[u]) {
            if (visited[x]) continue;
            q.push(x);
            visited[x] = 1;
        }
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n,m,x,a,b; cin >> n >> m;
    
    V.assign(n, 0);
    AL.assign(n, vi());
    visited.assign(n, 0);

    for (int i=0; i<n; i++) {
        cin >> V[i];
    }
    while (m--) {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    
    for (int i=0; i<n; i++) {
        if (visited[i]) continue;
        int res = bfs(i);
        if (res != 0) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    cout << "POSSIBLE";
}
