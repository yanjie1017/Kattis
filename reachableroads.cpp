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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m, r, a, b;
    cin >> n;
    while (n--) {
        cin >> m >> r;
        vector<vector<int>> M;
        vector<int> visited;
        M.assign(m, vector<int>());
        visited.assign(m, 0);
        while (r--) {
            cin >> a >> b;
            M[a].push_back(b); M[b].push_back(a);
        }
        int road = -1;
        for (int i=0; i<m; i++) {
            if (visited[i]) continue;
            //BFS
            queue<int> q;
            visited[i] = 1; q.push(i); 
            while (!q.empty()) {
                int curr = q.front(); q.pop();
                for (auto& x:M[curr]) {
                    if (!visited[x]) {
                        visited[x] = 1; q.push(x);
                    }
                }       
            }
            road++;
        }
        cout << road << endl;
    }
}