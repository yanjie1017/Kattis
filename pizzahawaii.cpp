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

    int n; cin >> n;
    while (n--) {
        int m; cin >> m;
        unordered_map<string, set<int>> F;
        unordered_map<string, set<int>> L;
        set<string> FS;
        set<string> LS;
        for (int i=0; i<m; i++) {
            string s; cin >> s; 
            int f; cin >> f;
            while (f--) {
                string x; cin >> x;
                if (F.find(x) == F.end()) F[x] = set<int>();
                F[x].insert(i);
                FS.insert(x);
            }
            int l; cin >> l;
            while (l--) {
                string x; cin >> x;
                if (L.find(x) == L.end()) L[x] = set<int>();
                L[x].insert(i);
                LS.insert(x);
            }
        }
        for (const auto& x:FS) {
            for (const auto& y:LS) {
                bool equal = true;
                if (F[x].size() != L[y].size()) equal = false;
                if (equal) {
                    auto itf = F[x].begin();
                    auto itl = L[y].begin();
                    while (itf != F[x].end()) {
                        if (*itf != *itl) {
                            equal = false; break;
                        }
                        itf++; itl++;
                    }
                }
                if (equal) cout << "(" << x << ", " << y << ")\n";
            }
        }
        cout << endl;
    }
}