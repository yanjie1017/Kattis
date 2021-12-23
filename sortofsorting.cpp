#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
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

bool compare(string a, string b) {
    return a.substr(0,2) < b.substr(0,2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n;
    while (cin >> n) {
        if (n==0) return 0;
        vector<string> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        stable_sort(v.begin(), v.end(), compare);
        for (auto& x:v) {
            cout << x << '\n';
        }
        cout << '\n';
    }
}
