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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1.in","r",stdin);

    string n, m; cin >> n >> m;
    string zero = "0";
    if (n.length() >= m.length()) {
        string front = n.substr(0, n.length()-m.length()+1);
        string back = n.substr(front.length(), n.length()-front.length());
        if (back == string(back.length(), '0')) {
            cout << front; return 0;
        }
        ll backzero = 0;
        for (ll i = back.length()-1; i>=0; i--) {
            if (back[i] != '0') break;
            backzero++;
        }
        cout << front << '.' << back.substr(0, back.length()-backzero);
    } else {
        ll backzero = 0;
        for (ll i = n.length()-1; i>=0; i--) {
            if (n[i] != '0') break;
            backzero++;
        }
        cout << m.substr(1, m.length()-1) << '.' << n.substr(0, n.length()-backzero);
    }
}