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

priority_queue<ii> A;
priority_queue<ii> D;
priority_queue<ii> H;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n, k; cin >> n >> k;
    for (ll i=0; i<n; i++) {
        ll a,d,h; cin >> a >> d >> h;
        A.emplace(a,i);
        D.emplace(d,i);
        H.emplace(h,i);
    }
    
    unordered_set<ll> ans;
    for (ll i=0; i<k; i++) {
        ans.insert(A.top().second);
        ans.insert(D.top().second);
        ans.insert(H.top().second);
        A.pop(); D.pop(); H.pop();
    }
    cout << ans.size();
}