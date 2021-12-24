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

    string s;
    unordered_map<string, int> M;
    while (cin >> s) {
        string x = s;
        for (auto& c:x) {
            c = tolower(c);
        }
        if (M[x]) {
            cout << '.' << ' ';
        } else {
            cout << s << ' ';
            M[x]++;
        }
    }
}