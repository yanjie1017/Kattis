#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
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

unordered_map<char, int> M = {
    {'B', 1}, {'F', 1}, {'P', 1}, {'V', 1},
    {'C', 2}, {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2},
    {'D', 3}, {'T', 3},
    {'L', 4}, 
    {'M', 5}, {'N', 5},
    {'R', 6}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    string s;
    while (cin >> s) {
        vector<int> ans; ans.push_back(0);
        for (int i=0; i<s.length(); i++) {
            if (M.find(s[i]) !=  M.end()) {
                if (M[s[i]] != ans.back()) {
                    ans.push_back(M[s[i]]);
                }
            }
            else ans.push_back(0);
        }
        for (int i=0; i<ans.size(); i++) {
            if (ans[i] != 0) cout << ans[i];
        }
        cout << '\n';
    }
}