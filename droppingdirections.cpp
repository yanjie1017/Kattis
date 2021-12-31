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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;

unordered_map<int, vector<int>> AL;
vector<vector<int>> visited; //0-AC; 1-BD;

void dfs(int curr, int prev) {
    int visited_index = 1;
    int next;
    for (int i=0; i<4; i++) {
        if (AL[curr][i] == prev) {
            if (i == 0 || i == 1) visited_index = 0;
            if (i%2 == 0) next = AL[curr][i+1];
            else next = AL[curr][i-1];
        }
    }

    if (visited[visited_index][curr]) return;
    visited[visited_index][curr] = 1;
    dfs(next, curr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int tc, n, g, a, b, c, d;
    cin >> tc;
    while (tc--) {
        cin >> n >> g; g--;
        AL.clear();
        visited.assign(2,vi(n,0));

        for (int i=0; i<n; i++) {
            cin >> a >> b >> c >> d;
            AL[i].push_back(--a); AL[i].push_back(--c);
            AL[i].push_back(--b); AL[i].push_back(--d);
        }

        dfs(g, AL[g][0]); dfs(g, AL[g][2]);

        int sign = 0;
        for (int i=0; i<n; i++) {
            int visited_index = 0;
            if (!visited[visited_index][i]) {
                sign++; dfs(i, AL[i][0]);
            }
            if (!visited[++visited_index][i]) {
                sign++; dfs(i, AL[i][2]);
            }
        }

        cout << sign << endl;
    }
}