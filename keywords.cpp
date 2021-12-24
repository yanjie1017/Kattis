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

    int n; cin >> n; cin.get();
    unordered_set<string> M;
    while (n--) {
        string s; getline(cin, s);
        for (auto& x:s) {
            if (x == '-') x = ' ';
            x = tolower(x);
        }
        M.insert(s);
    }
    cout << M.size();
    
}