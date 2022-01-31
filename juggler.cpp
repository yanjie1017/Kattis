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
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
        T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ii = pair<ll,ll>;

int main() {
    ll n; cin >> n;

    ordered_set<ii> o_set;
    unordered_map<ll,ll> orders;

    for (ll i=0; i<n; i++) {
        ll m; cin >> m;
        orders[m] = i;
        o_set.insert(ii(i,m));
    }

    ll total = 0;
    ll order = 1;
    ll curr = 0;
    while (!o_set.empty()) {
        ll k = orders[order];
        ii u = *o_set.find(ii(k,order));
        ll l = o_set.order_of_key(u);
        ll s = o_set.size();
        ll clk = ((curr-l)+s)%s;
        ll anticlk = ((l-curr)+s)%s;
        total += min(clk,anticlk);
        curr = l;
        o_set.erase(u);
        total++;
        order++;
    }
    cout << total;
}