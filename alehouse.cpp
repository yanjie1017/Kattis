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
typedef vector<int> vi;

vector<ii> Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n, k, a, b;
    cin >> n >> k;
    while (n--) {
        cin >> a >> b;
        Q.emplace_back(a,0);
        Q.emplace_back(b,1);
    }

    sort(Q.begin(), Q.end());

    ll maxn = 0;
    ll curr = 0;
    ll j = 0;
    for (int i=0; i<Q.size(); i++) {
        while (j<Q.size() && Q[j].first-Q[i].first <= k) {
            if (Q[j].second == 0) curr++;
            j++;
        }
        if (Q[i].second == 1) {
            maxn = max(maxn, curr);
            curr--;
        }
    }
    cout << maxn;
}