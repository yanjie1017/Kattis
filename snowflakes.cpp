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
typedef pair<int, int> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll t, n, x; cin >> t;
    while (t--) {
        cin >> n; ll sum = 0;
        unordered_set<ll> S;
        deque<ll> Q;
        while (n--) {
            cin >> x;
            if (S.find(x) != S.end()) {
                while (!Q.empty()) {
                    ll curr = Q.front();
                    Q.pop_front();
                    S.erase(curr);
                    if (curr == x) break;
                }
                S.insert(x);
                Q.push_back(x);
            } else {
                S.insert(x);
                Q.push_back(x);
                sum = max(sum, (ll)S.size());
            }            
        }
        cout << sum << endl;
    }

}
