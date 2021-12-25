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

    ll front, back; cin >> front >> back;
    vector<ll> F(front), B(back);
    for(auto& x:F) {
        cin >> x;
    }
    for(auto& x:B) {
        cin >> x;
    }

    vector<ii> ans;
    for(ll i = 0; i < front; ++i) {
        for(ll j = 0; j < back; ++j) {
            ans.emplace_back(F[i], B[j]);
        }
    }

    std::sort(ans.begin(), ans.end(), [](ii a, ii b) {
        if(a.first * b.second == b.first * a.second) {
            return a.first < b.first;
        }
        return a.first * b.second < b.first * a.second;
    });

    for(auto&  x:ans) {
        cout << '(' << x.first << ',' << x.second << ")" << endl;
    }
  
}