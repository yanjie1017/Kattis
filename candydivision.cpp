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
    set<ll> s;
    for(ll i = 1; i < sqrt(n)+2; i++) {
        if(n % i == 0) {
            s.insert(i);
            s.insert(n/i);
        }
    }
    for (auto& x:s) {
        cout << x-1 << ' ';
    }
}
