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

vector<int> W;
priority_queue<ii, vector<ii>, greater<ii>> Q;
int f,s,g,u,d; 

vector<int> next(int i) {
    vector<int> v;
    if (i+u < f) v.push_back(i+u);
    if (i-d >= 0) v.push_back(i-d);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >> f >> s >> g >> u >> d;
    s -= 1; g -= 1;

    W.assign(f, INT_MAX);
    W[s] = 0;
    Q.emplace(0,s);

    while (!Q.empty()) {
        int u = Q.top().second;
        int uw = Q.top().first;
        int vw = uw + 1;
        Q.pop(); 

        if (u == g) {
            cout << uw;
            return 0;
        }

        for (auto& v:next(u)) {
            if (vw < W[v]) {
                W[v] = vw;
                Q.emplace(vw, v);
            }
        }       
    }
    cout << "use the stairs";
}