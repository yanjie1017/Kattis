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
typedef pair<int , int8_t> ii;
typedef vector<ll> vi;

unordered_map<int, vector<ii>> AL;
vector<vector<int>> W;
vector<vector<int>> G;
priority_queue<tuple<int, int, int, int>, 
                vector<tuple<int, int, int, int>>, 
                greater<tuple<int, int, int, int>>> Q;
int n, k; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> n >> k; 
    G.assign(n, vector<int>(n));
    W.assign(n, vector<int>(n, INT_MAX));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x; cin >> x;
            G[i][j] = x;
            AL[x-1].emplace_back(i,j);
        }
    }
    for (auto& [i,j]:AL[0]) {
        W[i][j] = 0;
        Q.emplace(0, G[i][j], i, j);
    }

    while (!Q.empty()) {
        int ui = get<2>(Q.top()); 
        int uj = get<3>(Q.top());
        int uw = get<0>(Q.top());
        int un = get<1>(Q.top());
        Q.pop();
        if (un == k) {
            cout << uw; return 0;
        }
        for (auto& [vi,vj]:AL[un]) {
            int vw = uw + abs(ui-vi) + abs(uj-vj) ;
            if (vw < W[vi][vj]) {
                W[vi][vj] = vw;
                Q.emplace(vw, G[vi][vj], vi, vj);
            }
        }       
    }
    cout << -1;
}