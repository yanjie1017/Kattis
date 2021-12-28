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

    int n; 
    cin >> n;
    vi V(n);
    for (int i=0; i<n; i++) {
        cin >> V[i];
    }
    sort(V.rbegin(), V.rend());

    priority_queue<int> Q; int m;
    for (int i=0; i<n; i++) {
        m = min(i+1, V[i]);
        Q.push(m);
    }
    cout << Q.top();
}
