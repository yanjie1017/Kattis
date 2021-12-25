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

    int x = 0;
    vector<int> v(8);
    vector<int> s = {1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690};
    for(auto& x:v) {
        cin >> x;
    }
    for(int i=0; i<8; i++) {
        x += v[i] * s[i];
    }
    cout << 9699689 - x << "\n";
}