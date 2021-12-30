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

    int m,s,x; cin >> m >> s;
    vector<vi> V; V.assign(m, vi(s));
    for (int i=0; i<m; i++) {
        for (int j=0; j<s; j++) {
            cin >> V[i][j];
        }
    }
    
    set<int> S;
    for (int j=0; j<s; j++) {
        for (int i=0; i<m; i++) {
            S.insert(V[i][j]);
        }
        if (S.size() == j+1) break;
    }

    cout << S.size() << endl;
    for (auto& x:S) {
        cout << x << ' ';
    }
}
