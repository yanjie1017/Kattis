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

vi BI;
vector<unordered_set<int>> AL;
vector<ii> IN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n,a,b; cin >> n;
    BI.assign(n+1, -1); AL.assign(n+1, unordered_set<int>());
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        AL[a].insert(b);
        AL[b].insert(a);
        IN.emplace_back(a,b);
    }

    queue<int> Q;
    Q.push(1); BI[1] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int uw = BI[u]; int w;
        if (uw == 1) w = 0;
        else w = 1;

        for (auto& v:AL[u]) {
            if (BI[v] != -1) continue;
            BI[v] = w;
            Q.push(v);
        }
    }

    for (auto& [u,v]:IN) {
        if (BI[u] == 0 && BI[v] == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
