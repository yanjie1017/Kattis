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

    ll n, m; cin >> n;
    while (n--) {
        cin >> m;
        vector<ll> V(3*m);
        for (auto& x:V) {
            cin >> x;
        }
        sort(V.rbegin(), V.rend());
        ll total = 0;
        for (int i=1; i<2*m; i+=2) {
            total += V[i];
        }
        cout << total << endl;
    }
        
}
