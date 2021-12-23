#include <iostream>
#include <sstream>
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
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, k; cin >> n >> k;
    int maxn = 0;
    queue<int> q;
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        while (!q.empty() && q.front()+1000 <= t) {
            q.pop();
        }
        q.push(t);
        maxn = max(maxn, (int)q.size());
    }
    if (maxn%k == 0) {
        cout << maxn/k;
    } else {
        cout << maxn/k+1;
    }
}