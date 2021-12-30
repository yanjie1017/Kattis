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
    freopen("1.in","r",stdin);

    int n; string s; cin >> n >> s;
    string x = "";
    for (int i=1; i<=n; i++) {
        string c = to_string(i);
        x += c; 
        if (x != s.substr(0, x.size())) {
            cout << i;
            break;
        }
    }
}
