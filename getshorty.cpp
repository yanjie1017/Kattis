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
typedef vector<int> vi;

vector<vector<pair<int, double>>> AL;
vector<double> W;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m, a, b; double f;
    while (cin >> n >> m){
        if (n == 0 && m == 0) break;
        AL.assign(n, vector<pair<int, double>>());
        W.assign(n, 0);
        while (m--) {
            cin >> a >> b >> f;
            AL[a].emplace_back(b, f);
            AL[b].emplace_back(a, f);
        }
        priority_queue<pair<double, int>> Q;
        Q.emplace(1.0, 0);
        W[0] = 1;
        while (!Q.empty()) {
            int u = Q.top().second;
            double uw = Q.top().first;
            Q.pop();
            if (u == n-1) break;
            for (auto& [v,w]:AL[u]) {
                double vw = w * uw;
                if (vw <= W[v]) continue;
                W[v] = vw;
                Q.emplace(vw,v);
            }
        }
        cout << fixed << setprecision(4);
        cout << W[n-1] << endl;
    }
}
