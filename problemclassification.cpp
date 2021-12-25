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

    int n, m; cin >> n;
    unordered_map<string, vector<string>> M;
    map<string, int> A;
    while (n--) {
        string cat; cin >> cat >> m;
        A[cat] = 0;
        while (m--) {
            string word; cin >> word;
            M[word].push_back(cat);
        }
    }
    string text; int maxn = 0;
    while (cin >> text) {
        if (M.find(text) != M.end()) {
            for (auto& x:M[text]) {
                A[x]++;
                maxn = max(maxn, A[x]);
            }
        }
    }
    
    for (auto& x:A) {
        if (x.second == maxn) cout << x.first << endl; 
    }
}
