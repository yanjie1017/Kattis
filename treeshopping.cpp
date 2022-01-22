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
#include <utility>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, k; cin >> n >> k;
    vector<int> v(n);

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    int dff = INT_MAX;
    multiset<int> S;

    int i=0; int j;
    for (j=0; j<k; j++) {
        S.insert(v[j]);
    }
    dff = abs(*S.begin() - *S.rbegin());

    for (;j<n;j++) {
        S.erase(S.lower_bound(v[i]));
        i++;
        S.insert(v[j]);
        dff = min(dff,abs(*S.begin() - *S.rbegin()));
    }

    cout << dff << endl;
}
