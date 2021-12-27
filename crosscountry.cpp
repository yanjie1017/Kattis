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
typedef vector<ll> vi;

unordered_map<int, vector<ii>> AL;
vector<int> W;
priority_queue<ii, vector<ii>, greater<ii>> Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, s, t; cin >> n >> s >> t;
    W.assign(n, INT_MAX); 
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x; cin >> x;
            AL[i].emplace_back(x,j);
        }
    }

    Q.emplace(0,s);
    W[s] = 0;
    
    while (!Q.empty()) {
        int u = Q.top().second;
        int uw = Q.top().first;
        Q.pop(); 

        if (u == t) {
            cout << uw;
            return 0;
        }

        for (auto& [w,v]:AL[u]) {
            int vw = uw + w;
            if (vw < W[v]) {
                W[v] = vw;
                Q.emplace(vw, v);
            }
        }       
    }
}