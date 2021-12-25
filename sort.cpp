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
typedef tuple<ll, ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n, m; cin >> n >> m;
    unordered_map<ll, ll> fre;
    unordered_map<ll, ll> ind;
    set<ii, greater<ii>> s;
    while (n--) {
        ll x; cin >> x;
        fre[x]++;
        if (ind.find(x) == ind.end()) ind[x] = n;
    }
    for (auto& x:fre) {
        tuple<ll, ll, ll> t = {x.second, ind[x.first], x.first};
        s.insert(t);
    }
    for (auto& [a,b,c]:s) {
        for (ll i=0; i<a; i++) cout << c << ' ';
    }
}