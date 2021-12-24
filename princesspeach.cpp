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

    int n, l; cin >> n >> l;
    unordered_set<int> S;

    while (l--) {
        int x; cin >> x;
        S.insert(x);
    }

    for (int i=0; i<n; i++) {
        if (S.find(i) != S.end()) continue;
        cout << i << '\n';
    }
    cout << "Mario got " << S.size() << " of the dangerous obstacles.";
}