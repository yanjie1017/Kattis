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
#include <cctype>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m;
    while (cin >> n) {
        if (n==0) return 0;
        cin >> m;
        vector<string> v(m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char x; cin >> x;
                v[j].push_back(x);
            }
        }

        stable_sort(v.begin(), v.end(), [](string a, string b) {
            for(auto&x : a) x = tolower(x);
            for(auto&x : b) x = tolower(x);
            return a < b;
        });

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << v[j][i];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
