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

vector<vector<int>> G;
vector<vector<int>> visited;
vector<vector<int>> step;
vector<ii> star;

int n, m; 
int nb[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

vector<ii> neighbour(int x, int y, int z) {
    vector<ii> V;
    for (int i=0; i<4; i++) {
        int dx = z * nb[i][0]; int dy = z * nb[i][1];
        if (x+dx >= 0 && x+dx < n &&
            y+dy >= 0 && y+dy < m) 
            V.emplace_back(x+dx,y+dy); 
    }
    return V;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    
    cin >> n >> m;
    G.assign(n, vector<int>(m));
    visited.assign(n, vector<int>(m,0));
    step.assign(n, vector<int>(m,-1));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char x; cin >> x;
            G[i][j] = x - '0';
        }
    }

    queue<ii> Q;
    visited[0][0] = 1;
    step[0][0] = 0;
    Q.emplace(0,0); 
    while (!Q.empty()) {
        int ui = Q.front().first;
        int uj = Q.front().second;
        int un = G[ui][uj];
        int ud = step[ui][uj]; 
        Q.pop();
        
        for (auto& [vi,vj]:neighbour(ui,uj,un)) {
            if (visited[vi][vj]) continue;
            visited[vi][vj] = 1;
            step[vi][vj] = ud+1;
            Q.emplace(vi,vj);
        }
    }
    cout << step[n-1][m-1] << endl;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << step[i][j];
    //     }
    //     cout << endl;
    // }
}
