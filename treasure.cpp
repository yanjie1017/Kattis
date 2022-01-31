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

using ll = long long;
using ii = pair<ll,ll>;
using iii = tuple<int,int,int>;

vector<vector<char>> MAP;
vector<vector<int>> COST;
ll k,n,m; 
ii start, goal;

unordered_map<char, int> TERR = {
    {'.',1}, {'F',2}, {'M',3}, {'G',1}
};

vector<ii> nb(int r, int c) {
    vector<ii> v;
    vector<int> dr = {-1,+1,0,0};
    vector<int> dc = {0,0,+1,-1};
    for (int i=0; i<4; i++) {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 || cc < 0) continue;
        if (rr >= n || cc >= m) continue;
        if (MAP[rr][cc] == '#') continue;
        if (TERR[MAP[rr][cc]] > k) continue;
        v.emplace_back(rr,cc);
        
    }
    return v;
}

void dij() {
    priority_queue<iii, vector<iii>, greater<iii>> q;
    q.emplace(0, start.first, start.second);
    COST[start.first][start.second] = 0;

    while (!q.empty()) {
        int uw = get<0>(q.top()); 
        int ui = get<1>(q.top()); 
        int uj = get<2>(q.top()); 
        int ud = ceil((double)uw/k);
        q.pop();
        vector<ii> neigh = nb(ui, uj);

        for (auto& [vi,vj]:neigh) {
            int vw = uw + TERR[MAP[vi][vj]];
            int vd = ceil((double)vw/k);
            if (vd > ud) {
                vw = k * ud +  TERR[MAP[vi][vj]];
            } 
            if (vw >= COST[vi][vj]) continue;
            COST[vi][vj] = vw;
            q.emplace(COST[vi][vj],vi,vj);
        }       
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> n >> m >> k;
    MAP.assign(n, vector<char>(m));
    COST.assign(n, vector<int>(m,INT_MAX));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'S') start = ii(i,j);
            if (MAP[i][j] == 'G') goal = ii(i,j);
        }
    }
    dij();
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << COST[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    if (COST[goal.first][goal.second] == INT_MAX) cout << -1;
    else {
        cout << ceil((double)COST[goal.first][goal.second]/k);
    }
}