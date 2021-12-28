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

vector<vi> AL;
vi START;
vi VISITED;
int total;

void bfs(int x) {
    queue<int> Q;
    VISITED[x] = 1;
    Q.emplace(x); 
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop(); total++;
        for (auto& v:AL[u]) {
            if (VISITED[v]) continue;
            VISITED[v] = 1;
            Q.emplace(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int t,n,m,l,a,b; cin >> t;
    while (t--) {
        cin >> n >> m >> l;
        n++;
        AL.assign(n, vi());
        VISITED.assign(n, 0);
        START.clear();
        while (m--) {
            cin >> a >> b;
            AL[a].push_back(b);
        }
        while (l--) {
            cin >> a;
            START.push_back(a);
        }

        total = 0;
        for (auto& x:START) {
            if (VISITED[x]) continue;
            bfs(x);
        }
        cout << total << endl;
    }
}