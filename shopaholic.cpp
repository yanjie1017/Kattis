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

    priority_queue<ll> q;
    ll n; cin >> n;
    while (n--) {
        ll x; cin >> x;
        q.push(x);
    }
    ll total = 0;
    while (q.size() >= 3) {
        q.pop(); q.pop(); total += q.top(); q.pop();
    }
    cout << total;
}