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

    string n; int total = 0;
    map<string, int> t;
    while (getline(cin, n)) {
        t[n]++;
        total++;
    }
    for (auto& x:t) {
        cout << fixed << setprecision(6);
        cout << x.first << ' ' << ((double)x.second)/total * 100 << endl;
    }
}