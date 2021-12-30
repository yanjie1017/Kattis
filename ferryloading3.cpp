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

    int c, n, m, t; cin >> c; 
    
    while (c--) {
        cin >> n >> t >> m;
        vector<queue<ii>> q(2, queue<ii>());
        vector<int> v(m);

        for (int i=0;i<m; i++) {
            int l; string side; cin >> l >> side;
            if (side == "left") q[0].emplace(i,l);
            else q[1].emplace(i,l);
        }

        int time = 0;
        int i = 0;
        while (!q[0].empty() || !q[1].empty()) {
            int car = 0;
            int first = INT_MAX;

            if (!q[0].empty()) first = q[0].front().second;
            if (!q[1].empty()) {
                if (q[1].front().second < first) first = q[1].front().second;
            }
            time = max(first, time);

            while (!q[i].empty()) {
                if (car >= n) break;
                if (q[i].front().second > time) break;
                v[q[i].front().first] = time+t;
                q[i].pop();
                car++;
            }
            time += t;
            i ^= 1;
        }

        for (auto& x:v) {
            cout << x << endl;
        }
        cout << '\n';
    }
    
}
