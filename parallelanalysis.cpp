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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int tc, n, m, r, w; cin >> tc;
    for (int x=1; x<=tc; x++) {
        cin >> n;
        int total = 0;
        unordered_map<int,int> M;

        for (int i=0; i<n; i++) {
            cin >> m;
            int maxt = 0;

            for (int j=1; j<m; j++) {
                cin >> r;
                maxt = max(maxt, M[r]);
            }
            
            cin >> w;
            M[w] = ++maxt;
            total = max(total, M[w]);
        }

        cout << x << ' ' << total << endl;
    }
}