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

vector<vector<char>> G;
vector<vector<int>> visited;
vector<ii> star;

int n, m; 
int nb[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

vector<ii> neighbour(int x, int y) {
    vector<ii> V;
    for (int i=0; i<4; i++) {
        int dx = nb[i][0]; int dy = nb[i][1];
        if (x+dx >= 0 && x+dx < n &&
            y+dy >= 0 && y+dy < m &&
            G[x+dx][y+dy] == '-') 
            V.emplace_back(x+dx,y+dy);
        
    }
    return V;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    int t = 0;
    while (cin >> n >> m) {
        t++;

        G.assign(n, vector<char>(m));
        visited.assign(n, vector<int>(m,0));
        star.clear();

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                char x; cin >> x;
                G[i][j] = x;
                if (x == '-') star.emplace_back(i,j);
            }
        }

        int count = 0;
        for (auto& [i,j]:star) {
            if (visited[i][j]) continue;
            count++;
            queue<ii> Q;
            visited[i][j] = 1;
            Q.emplace(i,j); 
            while (!Q.empty()) {
                int ui = Q.front().first;
                int uj = Q.front().second;
                Q.pop();
                for (auto& [vi,vj]:neighbour(ui,uj)) {
                    if (visited[vi][vj]) continue;
                    visited[vi][vj] = 1;
                    Q.emplace(vi,vj);
                }
            }
        }
        cout << "Case " << t << ": " << count << endl;
    }
    
}
