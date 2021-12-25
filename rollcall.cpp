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

    string first, last; 
    map<string, set<string>> M;
    unordered_map<string, int> F;
    while (cin >> first) {
        cin >> last;
        if (M.find(last) == M.end()) M[last] = set<string>();
        M[last].insert(first);
        F[first]++;
    } 
    for (auto& last:M) {
        for (auto& first:last.second) {
            if (F[first] == 1) cout << first << endl;
            else cout << first << " " << last.first << endl;
        }
    }
}