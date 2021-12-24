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

    int n, m; cin >> n >> m; 
    string s; int x; 
    unordered_map<string, int> M;
    while (n--) {
        cin >> s >> x;
        M[s] = x;
    }
    int total = 0;
    while (cin >> s) {
        if (s == ".") {
            cout << total << '\n';
            total = 0;
        }
        total += M[s];
    }
}