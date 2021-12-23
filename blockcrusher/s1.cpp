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

typedef pair<int, int> ii;
typedef pair<int, ii> pp;

vector<vector<int>> grid;
vector<vector<int>> visited;
vector<vector<int>> weight;
vector<vector<ii>> prevnode;
int R, C; 

vector<ii> find_nb(ii curr) {
    vector<ii> nb;
    int r=curr.first; int c=curr.second;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (i==0 && j==0) continue;
            int newr = r+i; int newc = c+j;
            if (newr >= 0 && newr < R && newc >= 0 && newc < C) {
                nb.push_back(ii(newr, newc));
            }
        }
    }
    return nb;
}

ii bfs() {
    priority_queue<pp, vector<pp>, greater<pp>> q;
    ii lastnode;
    int i = 0;
    for (int j=0; j<C; j++) {
        prevnode[i][j] = ii(-1,-1);
        visited[i][j] = 1;
        weight[i][j] = grid[i][j];
        q.emplace(weight[i][j],ii(i,j));
    }
    while (!q.empty()) {
        ii u = q.top().second; int w = q.top().first; q.pop();
        if (u.first == R-1) {
            lastnode = u; break;
        }
        
        vector<ii> nb = find_nb(u);
        for (auto v:nb) {
            int i = v.first; int j =v.second;
            if (!visited[i][j]) {
                prevnode[i][j] = u;
                visited[i][j] = 1;
                weight[i][j] =  grid[i][j] + w;
                q.emplace(weight[i][j],v);
            }
        }
    }
    return lastnode;
}

void fill(ii lastnode) {
    ii curr = lastnode;
    while (true) {
        int i = curr.first; int j = curr.second;
        grid[i][j] = -1;
        curr = prevnode[i][j];
        if (curr.first == -1) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    freopen("1.in","r",stdin);
    while (true) {
        cin >> R >> C;
        if (R==0 && C ==0) return 0;
        grid.assign(R, vector<int>(C));
        visited.assign(R, vector<int>(C));
        weight.assign(R, vector<int>(C));
        prevnode.assign(R, vector<ii>(C));
        for (int i=0; i<R; i++) {
            string row; cin >> row;
            for (int j=0; j<C; j++) {
                grid[i][j] = row[j] - '0';
            }
        }

        ii lastnode = bfs(); 
        fill(lastnode);
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (grid[i][j] == -1) cout << ' ';
                else cout << grid[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
        
    }
}