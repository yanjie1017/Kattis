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
typedef pair<int, int> ii;
typedef vector<int> vi;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1.in","r",stdin);

    set<int> S;
    for (int i=100; i<=999; i++) {
        S.insert(i);
    }

    int n, x, y; 
    cin >> n; 
    while (n--) {
        string s; cin >> s; 
        x = stoi(s);
        y = stoi(s.substr(0,3)); 
    
        auto it = S.find(y); 
        int ans; int dff = INT_MAX;
        if (next(it) != S.end()) it++;
        for (int i=0; i<3; i++) {
            string a = to_string(*it);
            string b = a; reverse(b.begin(), b.end());
            string c = a + b;
            int p = stoi(c);
            if (abs(p-x) <= dff) {
                ans = p;
                dff = abs(p-x);
            }
            if (it == S.begin()) break;
            it--;
        }

        cout << ans << endl;
    }

}