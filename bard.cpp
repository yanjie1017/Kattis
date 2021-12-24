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

    int n, e, m; cin >> n >> e;

    vector<set<int>> M(n+1);
    int bard = 0;

    while (e--) {
        cin >> m;
        vector<int> v(m);
        bool isPresent = false;

        for (auto& x:v) {
            cin >> x;
            if (x == 1) isPresent = true;
        }

        if (isPresent) {
            for (auto& x:v) {
                M[x].insert(bard);
            }
            bard++;
        } else {
            set<int> all;
            for (auto& x:v) {
                for (auto& y:M[x]) all.insert(y);
            }
            for (auto& x:v) M[x]=all;
        }
    }
    for (int i=1; i<n+1; i++) {
        if (M[i].size() == M[1].size()) cout << i << '\n';
    }
}