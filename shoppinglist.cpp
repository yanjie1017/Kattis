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

    int n, m; cin >> n >> m;
    map<string, int> M;
    set<string> ans;
    for (int i=0; i<n; i++) {
        unordered_set<string> indi;
        for (int j=0; j<m; j++) {
            string s; cin >> s;
            indi.insert(s);
        }
        for (auto& x:indi) {
            M[x]++;
            if (M[x] == n) ans.insert(x);
        }
    }
    cout << ans.size() << endl;
    for (auto& x:ans) {
        cout << x << endl;
    }
}