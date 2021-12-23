#include <iostream>
#include <sstream>
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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    char n, m; vector<char> N; 
    ll index = 0;
    while (cin >> n) {
        N.push_back(n);
        if (n == '1') index = N.size();
    } 

    ll M = N.size() - index; //numZeros
    ll Nsize = N.size() - M - 1;

    if (M+1 <= Nsize) {
        for (ll i=0; i<Nsize-M; i++) cout << N[i];

        ll backzero = 0;
        for (ll i=Nsize-1; i>=Nsize-M; i--) {
            if (N[i] != '0') break;
            backzero++;
        }

        if (Nsize-M < Nsize-backzero) cout << '.';
        for (ll i=Nsize-M; i<Nsize-backzero; i++) cout << N[i];
        
    } else {
        for (ll i=0; i<M+1-Nsize; i++) {
            cout << '0';
        }
        cout << '.';
        ll backzero = 0;
        for (ll i=Nsize-1; i>=Nsize-M; i--) {
            if (N[i] != '0') break;
            backzero++;
        }
        for (ll i=Nsize-M; i<Nsize-backzero; i++) cout << N[i];
    }
}