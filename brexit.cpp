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
typedef tuple<int, int, int> iii;
typedef vector<int> vi;

vector<int> P;
vector<int> R;
vector<int> visited;
vector<vi> AL;
int c, p, x, s, u, v;

void khans() {
    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto& v:AL[u]) {
            if (visited[v]) continue;
            R[v]--;
            if (R[v] <= (P[v]/2)) {
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> c >> p >> x >> s;
    AL.assign(c+1, vi()); 
    visited.assign(c+1, 0); 
    P.resize(c+1); R.resize(c+1);

    while (p--) {
        cin >> u >> v;
        AL[u].emplace_back(v);
        AL[v].emplace_back(u);
        P[u]++; P[v]++;
        R[u]++; R[v]++;
    }

    if (x == s) {
        cout << "leave"; return 0;
    }

    khans();

    if (R[x] <= (P[x]/2)) cout << "leave";
    else cout << "stay";
}
