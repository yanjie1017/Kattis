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
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;

bool cmp(iii a, iii b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    return get<0>(a) > get<0>(b);
}

unordered_map<int, vector<ii>> AL;
vector<int> W;
vector<int> N;
vector<int> V;
priority_queue<iii, vector<iii>, decltype(&cmp)> Q(cmp);
int m, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> m; 
    W.assign(m+1, INT_MAX);
    N.assign(m+1, 0);
    V.assign(m+1, 0);
    for (int i=1; i<=m; i++) {
        cin >> V[i];
    }
    cin >> n;
    while (n--) {
        int a,b,d; cin >> a >> b >> d;
        AL[a].emplace_back(b,d);
        AL[b].emplace_back(a,d);
    }

    Q.emplace(0,V[1],1);
    W[1] = 0; N[1] = V[1]; 

    while (!Q.empty()) {
        int u = get<2>(Q.top()); 
        int uw = get<0>(Q.top());
        int un = get<1>(Q.top());
        Q.pop();

        if (u == m) {
            cout << uw << ' ' << un;
            return 0;
        }
        
        for (auto& [v,w]:AL[u]) {
            int vw = uw + w;
            int vn = un + V[v];

            if (vw < W[v]) {
                W[v] = vw;
                N[v] = vn;
                Q.emplace(W[v], N[v], v);
            } else if (vw == W[v] && vn > N[v]) {
                W[v] = vw;
                N[v] = vn;
                Q.emplace(W[v], N[v], v);
            }
        }      
    }
    cout << "impossible";
}