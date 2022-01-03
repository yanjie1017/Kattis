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

vector<vi> visited;
queue<ii> q;
int n; 

void nb(ii curr) {
    vi dr = {+2,+2,-2,-2,+1,+1,-1,-1};
    vi dc = {+1,-1,+1,-1,+2,-2,+2,-2};
    
    for (int i=0; i<8; i++) {
        int rr = curr.first + dr[i];
        int cc = curr.second + dc[i];
        if (rr < 0 || cc < 0) continue;
        if (rr >= n || cc >= n) continue;
        if (!visited[rr][cc]) {
            visited[rr][cc] = 1;
            q.push(ii(rr,cc));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("knight.in","r",stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        vi newvi; newvi.assign(n, 0); 
        visited.push_back(newvi);
        for (int j=0; j<n; j++) {
            char k; cin >> k;
            if (k == '#')
                visited[i][j] = -1;
            if (k == 'K') {
                visited[i][j] = 1;
                q.push(ii(i,j));
            }
        }
    }

    int layer = 0;
    int curr_layer = 1;
    while (!q.empty()) {
        ii curr = q.front(); q.pop(); 
        curr_layer--;
        if (curr.first == 0 && curr.second == 0) {
            cout << layer;
            return 0;
        }
        nb(curr);
        if (curr_layer == 0) {
            curr_layer = q.size();
            layer++;
        }
    }
    cout << -1;
}