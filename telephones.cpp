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
typedef pair<int , int> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m, src, dest, start, dur, a, b, START, END;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) return 0;
        vector<ii> v;
        while (n--) {
            cin >> src >> dest >> start >> dur;
            if (dur == 0) continue;
            v.emplace_back(start, start+dur);
        }
        while (m--) {
            cin >> a >> b;
            START = a; END = a + b;
            int total = 0;
            for (auto& [a,b]:v) {
                if (b <= START || a >= END) continue;
                total++;
            }
            cout << total << endl;
        }
    }
}