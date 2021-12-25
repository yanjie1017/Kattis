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
    unordered_map<string, vector<int>> M;
    while (n--) {
        string x; int y; cin >> x >> y;
        if (M.find(x) == M.end()) M[x] = vector<int>();
        M[x].push_back(y);
    }
    for (auto& x:M) {
        sort(x.second.begin(), x.second.end());
    }
    cin >> n;
    while (n--) {
        string x; int y; cin >> x >> y;
        cout << M[x][y-1] << endl;
    }
}