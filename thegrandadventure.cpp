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

unordered_map<char, char> m = {
    {'b', '$'},
    {'j', '*'},
    {'t', '|'},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
   
    while (n--) {
        stack<int> bag; 
        string s; cin >> s;
        bool finished = true;
        for (int i=0; i<s.length(); i++) {
            char x = s[i];
            if (x == '$' || x == '*' || x == '|') {
                bag.push(x);
            }  else if (x == 'b' || x == 't' || x == 'j') {        
                if (!bag.empty() && bag.top() == m[x]) {
                    bag.pop();
                } else {
                    finished = false;
                }
            }
        }
        if (finished && bag.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}