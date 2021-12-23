#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
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

ld longedge  = pow(2.0, -3/4.0);
ld shortedge = pow(2.0, -5/4.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n; vector<ll> v;
    cin >> n;
    for (int i=1; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    ll total = 1; ld tape = 0;
    for(ll i = 0; i < v.size(); i++) {
        tape += total * longedge;
        longedge /= 2;
        swap(shortedge, longedge);
        total *= 2;
        total -= v[i];
        if (total <= 0) {
            cout << fixed << setprecision(9);
            cout << tape << endl; 
            return 0;
        }
    }

    cout << "impossible" << endl;
}