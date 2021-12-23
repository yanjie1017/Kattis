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

int INT_MAX = 2000000000;
struct edge {
    int e;
    int t0;
    int p;
    int d;
};

vector<vector<edge>> AL;
vector<int> timetaken;

void bfs(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    timetaken[s] = 0;
    q.emplace(0,s); 
    
    while (!q.empty()) {
        int u = q.top().second; int t = q.top().first; q.pop();
        

        for (auto& v:AL[u]) {
            int v_t = v.t0;
            while (v_t < t) {
                if (v.p == 0) break;
                v_t += v.p;
            }
            if (v_t < t) continue;
            int curr_t = v_t + v.d;
            if (timetaken[v.e] > curr_t) {
                timetaken[v.e] = curr_t;
                q.emplace(curr_t, v.e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    
    int n, m, q, s;
    while (cin >> n) {
        cin >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) return 0;

        AL.assign(n, vector<edge>());
        timetaken.assign(n, INT_MAX);

        for (int i=0; i<m; i++) {
            int u, v, t, p, d; cin >> u >> v >> t >> p >> d;
            edge e = {v,t,p,d};
            AL[u].emplace_back(e);
        }

        bfs(s);

        for (int i=0; i<q; i++) {
            int x; cin >> x;
            if (timetaken[x] == INT_MAX) cout << "Impossible";
            else cout << timetaken[x];
            cout << '\n';
        }
        AL.clear();
        timetaken.clear();
        cout << '\n';
    }
}