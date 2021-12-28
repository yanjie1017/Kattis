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
typedef vector<int> vi;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, x; 
    cin >> n;

    queue<int> Q;
    priority_queue<int, vector<int>, greater<int>> PQ;
    unordered_map<int, int> M;

    for (int i=0; i<n; i++) {
        cin >> x; 
        Q.push(x);
        M[x]++;
        if (i == n-1 && x != n+1) {
            cout << "Error";
            return 0;
        }
    }
    for (int i=1; i<=n+1; i++) {
        if (M.find(i) == M.end()) {
            PQ.push(i);
        }
    }
    if (PQ.empty()) {
        cout << "Error";
        return 0;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        cout << PQ.top() << endl;
        PQ.pop();
        M[u]--;
        if (M[u] == 0) {
            PQ.push(u);
        }
    }
}
