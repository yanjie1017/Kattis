#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <numeric>
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

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

vector<vector<int>> V;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1.in","r",stdin);

    int p; cin >> p;
    while (p--) {
        int index; ll denom; ld decim;
        cin >> index >> denom >> decim;
        
        long double DFF = 1;
        ll DENOM, NUMER;
        for (; denom > 0; denom--) {
            ld numer = denom * decim;
            ll num = round(numer);
            long double dff = abs(decim - (long double)num/denom);
            if (dff < DFF) {
                DFF = dff;
                DENOM = denom;
                NUMER = num;
            }
        }
        int d = std::gcd(NUMER, DENOM);
        NUMER /= d;
        DENOM /= d;
        cout << index << ' ' << NUMER << '/' << DENOM << endl;
    }
}