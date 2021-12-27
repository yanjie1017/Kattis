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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n, m; 
    while (cin >> n >> m) {
        if (n == 0 && m == 0) return 0;
        unordered_map<ll, ll> M;
        ll total = 0;
        while (n--) {
            ll x; cin >> x;
            if (M.find(x) == M.end()) M[x]++;
        }
        while (m--) {
            ll x; cin >> x;
            if (M[x] == 1) {
                total++;
                M[x] = 0;
            }
        }
        cout << total << endl;
    }
}
