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
typedef vector<ll> vi;

unordered_map<char, vector<string>> AL;
vector<string> DB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    for (char x='a'; x <= 'z'; x++) {
        AL[x] = vector<string>();
    }

    string prev; ll n; cin >> prev >> n;

    while (n--) {
        string s; cin >> s;
        AL[s[0]].push_back(s);
        DB.push_back(s);
    }

    bool isFound = false; string first;
    for (int i=0; i<DB.size(); i++) {
        string u = DB[i];
        if (u.front() == prev.back()) {
            if (AL[u.back()].size() == 0) {
                cout << u << '!' << endl;
                return 0;
            }
            if (AL[u.back()].size() == 1 && AL[u.back()][0] == u) {
                cout << u << '!' << endl;
                return 0;
            }
            if (!isFound) {
                first = u;
                isFound = true;
            }
        }
    }
    if (isFound) cout << first << endl;
    else cout << '?' << endl;
}
