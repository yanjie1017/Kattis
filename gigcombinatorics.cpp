#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <numeric>
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;

ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    vector<vi> v; v.assign(n+1, vi(3,0));
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        if (x == 1) v[i][0] = (v[i-1][0] + 1) % mod;
        else v[i][0] = v[i-1][0];
        if (x == 2) v[i][1] = (v[i-1][1]*2 + v[i-1][0]) % mod;
        else v[i][1] = v[i-1][1];
        if (x == 3) v[i][2] = (v[i-1][2] + v[i-1][1]) % mod;
        else v[i][2] = v[i-1][2];
    }
    cout << v[n][2];
}