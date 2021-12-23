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

unordered_map<string, ll> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in","r",stdin);

    int m; cin >> m;
    string s; 
    while (m--) {
        cin >> s;
        for (int i=1; i <= s.length(); i++) {
            M[s.substr(0, i)]++;
        }
    }
    int n; cin >> n;
    while (n--) {
        cin >> s;
        cout << M[s] << '\n';
    }
}