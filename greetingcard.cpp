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
#include <utility>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll n; cin >> n;
    unordered_set<pair<ll,ll>, pair_hash> S;
    vector<ii> V;
    while (n--) {
        ll a, b; cin >> a >> b;
        S.emplace(a,b);
        V.emplace_back(a,b);
    }

    ll c = 0;
    for (auto& [x,y]:V) {
        vector<ii> cmp = {
            {0, 2018}, {0, -2018}, {2018, 0}, {-2018, 0}, 
            {1680, 1118}, {1680, -1118}, {1118, 1680}, {1118, -1680},
            {-1680, 1118}, {-1680, -1118}, {-1118, 1680}, {-1118, -1680},
        };
        for (auto& [i,j]:cmp) {
            ii target = {x+i, y+j};
            if (S.find(target) != S.end()) {
                c++;
            }
        }
    }
    cout << c/2;
}
