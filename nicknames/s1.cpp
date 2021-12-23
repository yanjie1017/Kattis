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
typedef pair<int, int> ii;
typedef vector<int> vi;

unordered_map<char, set<string>> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in","r",stdin);
    
    for (char i='a'; i<='z'; i++) {
        s[i] = set<string>();
    }

    int n; cin >> n;
    while (n--) {
        string x; cin >> x;
        s[x[0]].emplace(x);
    }
    int m; cin >> m;
    while (m--) {
        string y; cin >> y;
        if (y.length() == 1) {
            cout << s[y[0]].size() << '\n';
        } else {
            int count = 0;
            auto found = s[y[0]].lower_bound(y);
            if (found == s[y[0]].end()) cout << count << '\n';
            else {
                while (found != s[y[0]].end()) {
                    if (y == (*found).substr(0,y.length())) {
                        count += 1; found++;
                    }
                    else break;
                }
                cout << count << '\n';
            }
        }
    }
}