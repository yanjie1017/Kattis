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

    int p, t; cin >> p >> t;
    vector<int> P(p);
    vector<int> T(t);
    for (auto& x:P) {
        cin >> x;
    }
    for (auto& x:T) {
        cin >> x;
    }
    sort(T.begin(), T.end(), greater<int>());

    vector<int> X;
    unordered_set<int> Y;
    for (auto& x:P) {
        int minD = INT_MAX; int tree = -1;
        for (auto& y:T) {
            if (abs(y-x) <= minD) {
                minD = abs(y-x);
                tree = y;
            }
        }
        X.push_back(tree);
        Y.insert(tree);
    }
    cout << X.size() - Y.size();
    
}