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

    ll n; cin >> n;
    unordered_map<ll, ll> M;
    ll awk = n;
    for (ll i=0; i<n; i++) {
        ll x; cin >> x;
        if (M.find(x) == M.end()) M[x] = i;
        else {
            awk = min(awk, i-M[x]);
            M[x] = i;
        }
    }
    cout << awk;
}
