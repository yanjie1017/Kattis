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

    int n, m; cin >> n;
    while (n--) {
        cin >> m;
        int total = 0; 
        vector<int> v;
        for (int i=0; i<m; i++) {
            int x; cin >> x;
            v.push_back(x);
            total += x;
        }
        double avg = (double)total / m;
        int c = 0;
        for (int i=0; i<m; i++) {
            if (v[i] > avg) c++;
        }
        cout << fixed << setprecision(3);
        cout << 100 * (double)c / m << "%" << endl;
    }
}