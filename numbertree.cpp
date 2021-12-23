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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    string s; cin >> s;
    int root = pow(2, n+1);
    int x=1;
    for (int i=0; i<s.length(); i++) {
        x *= 2;
        if (s[i] == 'R') {
            x++;
        }
    }
    cout << root-x;
}