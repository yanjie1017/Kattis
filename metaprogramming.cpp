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

    string n;
    unordered_map<string, int> dic;
    while (cin >> n) {
        if (n == "define") {
            int x; string var; cin >> x >> var;
            dic[var] = x;
            continue;
        }
        string a, b; char op; 
        cin >> a >> op >> b;
        if (dic.find(a) == dic.end() || dic.find(b) == dic.end()) {
            cout << "undefined" << endl;
            continue;
        }
        cout << boolalpha;
        switch (op)
        {
        case '=':
            cout << (dic[a] == dic[b]) << endl; break;
        case '<':
            cout << (dic[a] < dic[b]) << endl; break;
        case '>':
            cout << (dic[a] > dic[b]) << endl; break;
        }
    }
}