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

    int n, m; cin >> n;
    while (n--) {
        cin >> m;
        vector<ld> V;
        while (m--) {
            ll o; cin >> o;
            ld total = 0;
            while (o--) {
                ld p; cin >> p;
                total += p;
            }
            V.push_back(total);
        }
        sort(V.begin(), V.end());

        ld temp = 0;
        ld avg = 0;
        for (int i=0; i<V.size(); i++) {
            temp += V[i];
            avg += temp;
        }
        avg /= V.size();
        cout << fixed << setprecision(7);
        cout << avg << '\n';
    }
}
