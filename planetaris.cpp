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

    int n, m; cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        int x; cin >> x;
        q.push(x);
    }
    int total = 0;
    while (!q.empty() && m-q.top()-1 >= 0) {
        m -= (q.top()+1);
        total++;
        q.pop();
    }
    cout << total;
}
