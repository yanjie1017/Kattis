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

vector<int> W;
vector<int> B;

vector<int> nb(int x) {
    vector<int> V;
    for (auto& i:B) {
        int y = x+i;
        y = max(0,y);
        y = min(3600,y);
        V.push_back(y);
    }
    return V;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int t, n, target, x;
    cin >> t;
    while (t--) {
        cin >> n >> target;
        W.assign(3601, INT_MAX); 
        B.assign(n,0);

        for (int i=0; i<n; i++) {
            cin >> B[i];
        }

        queue<int> Q;
        Q.push(0); W[0] = 0;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            int uw = W[u];
            uw++;
            for (auto& v:nb(u)) {
                if (uw >= W[v]) continue;
                W[v] = uw;
                Q.push(v);
            }
        }
        for (int i=target; i<W.size(); i++) {
            if (W[i] != INT_MAX) {
                cout << W[i] << ' ' << i-target << endl;
                break;
            }
        }
        
    }
}
