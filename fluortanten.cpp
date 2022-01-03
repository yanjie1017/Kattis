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
typedef pair<ll, ll> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("flo.in","r",stdin);

    ll total = 0;
    ll net = 0;
    vector<ll> v;
    priority_queue<ll> t;
    ll n; cin >> n;
    for (ll i=1; i<=n-1; i++) {
        ll j; cin >> j;
        if (j == 0) {
            i--; continue;
        }
        total += (i*j);
        net += j;
        v.push_back(j);
    }
    t.push(net);
    for (ll i=0; i<n; i++) {
        net -= v[i];
        t.push(net);
    }
    cout << total+t.top();
}