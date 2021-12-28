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

    ll t, n, x; cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (n--) {
            cin >> x;
            pq.push(x);
        }
        ll total = 0;
        while (pq.size() >= 2) {
            ll curr = pq.top(); pq.pop();
            curr += pq.top(); pq.pop();
            total += curr;
            pq.push(curr);
        }
        cout << total << endl;
    }
    
}
