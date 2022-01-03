#include <iostream>
#include <sstream>
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
typedef pair<int, int> ii;
typedef vector<int> vi;

int r, c; 
vector<vi> visited;
vector<ii> starting;

int numOfCycle;
bool isCycle;


vector<ii> nb(ii curr) {
    vi dr = {+1,+1,+1,-1,-1,-1,0,0};
    vi dc = {0,-1,+1,0,-1,+1,-1,+1};
    vector<ii> v;
    
    for (int i=0; i<8; i++) {
        int rr = curr.first + dr[i];
        int cc = curr.second + dc[i];
        if (rr < 0 || cc < 0) continue;
        if (rr >= r || cc >= c) continue;
        v.push_back(ii(rr,cc));
    }
    return v;
}

void cycle(ii v) {
    visited[v.first][v.second] = 1;
    for (auto& x:nb(v)) {
        if (!visited[x.first][x.second]) cycle(x);
        if (visited[x.first][x.second] == 1) isCycle = true;
    } 
    visited[v.first][v.second] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("amoeba.in","r",stdin);

    cin >> r >> c;
    visited.assign(r, vi(c,0));

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            char t; cin >> t;
            if (t == '#') starting.push_back(ii(i,j));
            if (t == '.') visited[i][j] = 2;
        }
    }
    numOfCycle = 0;
    for (auto& x:starting) {
        isCycle = false;
        if (!visited[x.first][x.second]) {
            cycle(x);
            if (isCycle) numOfCycle++;
        }
    }
    cout << numOfCycle;
}