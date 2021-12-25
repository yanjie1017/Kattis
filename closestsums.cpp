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

    int n, m; int c = 1;
    while (cin >> n) {
        vector<int> v(n);
        set<int> s;
        for (auto& x:v) cin >> x;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                s.insert(v[i] + v[j]);
            }
        }
        cout << "Case " << c << ":\n";
        cin >> m;
        while (m--) {
            int x; cin >> x; 
            int dff = INT_MAX; int ans = 0;
            for (auto& sum:s) {
                if (abs(sum-x) < dff) {
                    ans = sum;
                    dff = abs(sum-x);
                }
            }
            cout << "Closest sum to " << x << " is " << ans << ".\n";
        }
        c++;
    }
}