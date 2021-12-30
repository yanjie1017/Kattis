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

vector<int> HL;
vector<int> HI;
vector<vi> AL;
queue<int> Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, h, l, u, v; 
    cin >> n >> h >> l;
    AL.assign(n, vi());
    HI.assign(n,INT_MAX);
    
    while (h--) {
        cin >> u;
        HL.push_back(u);
        Q.push(u);
        HI[u] = 0;
    }

    while (l--) {
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        int hi = HI[u];
        hi++;
        for (auto& v:AL[u]) {
            if (HI[v] != INT_MAX) continue;
            HI[v] = hi;
            Q.push(v);
        }
    }

    int hi = 0; int ans = 0;
    for (int i=0; i<n; i++) {
        if (HI[i] > hi) {
            hi = HI[i];
            ans = i;
        }
    }
    cout << ans;
}
