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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    vi v; bool possible = false;
    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        v.push_back(n);
    }

    for (ll i=0; i<v.size()-1; i++) {
        if (possible) break;

        string s1 = to_string(v[i]); ll v1 = v[i];
        string s2 = to_string(v[i+1]); ll v2 = v[i+1];

        if (s1.size() != s2.size()) continue;

        for (ll j=0; j<s1.size(); j++) {
            string temp1 = s1;
            string r1(1, '9');
            temp1.replace(j, 1, r1);
            if (stoll(temp1) > v2) {
                v[i] = stoll(temp1);
                possible = true; break;
            }
            string temp2 = s2;
            string r2(1, '0'); string r2_(1, '1');
            if (j == 0 && s2.size() != 1) r2 = r2_;
            temp2.replace(j, 1, r2);
            if (stoll(temp2) < v1) {
                v[i+1] = stoll(temp2);
                possible = true; break;
            }
        }
    }
    if (!possible) {
        cout << "impossible"; return 0;
    }
    for (ll i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}