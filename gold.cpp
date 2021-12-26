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

vector<ii> nb = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<vector<char>> M;
vector<vector<int>> visited;

int n,m,c; 
int startX, startY;

void dfs(int i, int j) {
    if (M[i][j] == '#') return;
    if (visited[i][j]) return;

    visited[i][j] = 1;
    if (M[i][j] == 'G') c++;

    for (int a=0; a<4; a++) {
        int x = i + nb[a].first;
        int y = j + nb[a].second;
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (M[x][y] == 'T') return;
        }
    }
    for (int a=0; a<4; a++) {
        int x = i + nb[a].first;
        int y = j + nb[a].second;
        if (x >= 0 && x < n && y >= 0 && y < m) {
            dfs(x,y);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> m >> n;
    M.assign(n, vector<char>(m));
    visited.assign(n, vector<int>(m,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char x; cin >> x;
            M[i][j] = x;
            if (x == 'P') {
                startX = i;
                startY = j;
            }
        }
    }

    c = 0;
    dfs(startX, startY);

    cout << c;
    
}