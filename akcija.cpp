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

    int n; cin >> n;
    priority_queue<int> q;
    while (n--) {
        int x; cin >> x;
        q.push(x);
    }
    int total = 0;
    while (q.size() >= 3) {
        total += q.top(); q.pop();
        total += q.top(); q.pop();
        q.pop();
    }
    while (!q.empty()) {
        total += q.top(); q.pop();
    }
    cout << total;
}