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

    ll n; cin >> n;
    vector<ll> V(n);
    for (auto& x:V) {
        cin >> x;
    }
    sort(V.begin(), V.end());
    ll total = 0;
    for (int i=0; i<V.size()-1; i++) {
        total += pow(V[i+1]-V[i], 2);
    }
    cout << total;
}
