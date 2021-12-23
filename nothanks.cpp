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

    int n; cin >> n; vector<int> v(n);
    for (auto& x:v) cin >> x;

    sort(v.begin(), v.end());
    int total = 0; 
    bool isCons = false;
    for (int i=0; i<n-1; i++) {
        if (v[i+1] - v[i] != 1) {
            if (!isCons) total += v[i];
            isCons = false;
        }
        else {
            if (!isCons) total += v[i];
            isCons = true;
        }
    }
    if (!isCons) total += v.back();
    cout << total;
}