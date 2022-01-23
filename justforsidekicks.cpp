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
#define LSB(S) ((S) & -(S))
using namespace std;

using ll = long long;

class Fenwick {
    private:
        vector<ll> ft;
    public:
        Fenwick(ll n) {ft.assign(n+1,0);}

        void update(ll i, ll v) {
            for (; i < (ll)ft.size(); i += LSB(i)) {
                ft[i] += v;
            }
        }
        ll rsq(ll i) {
            ll sum = 0;
            for (;i ; i -= LSB(i)) sum += ft[i];
            return sum;
        }
        ll rsq(ll l, ll r) {
            return rsq(r) - rsq(l-1);
        } 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, q; cin >> n >> q;

    vector<ll> V(7,0);
    vector<ll> D(n+1,0);
    vector<Fenwick> fenwick(7, Fenwick(n));
    for (int i=1; i<=6; i++) {
        cin >> V[i];
    }
    
    for (int i=1; i<=n; i++) {
        char x; cin >> x;
        D[i] = x-'0';
        fenwick[x-'0'].update(i,1);
    }

    while (q--) {
        int command; cin >> command;
        ll l, r; cin >> l >> r;
        switch (command)
        {
        case 1:
            fenwick[D[l]].update(l,-1);
            D[l] = r;
            fenwick[D[l]].update(l,+1);
            break;
        case 2:
            V[l] = r;
            break;
        case 3:
            ll total = 0;
            for (int i=1; i<=6; i++) {
                total += fenwick[i].rsq(l,r) * V[i];
            }
            cout << total << endl;
            break;

        }

    }

    
}
