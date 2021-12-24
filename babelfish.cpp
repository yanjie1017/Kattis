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

    string input;
    unordered_map<string, string> dic;
    while (getline(cin, input)) {
        if (input == "") break;
        stringstream s(input);
        string a, b;
        s >> a >> b;
        dic[b] = a;
    }
    while (cin >> input) {
        if (dic.find(input) == dic.end()) cout << "eh";
        else cout << dic[input];
        cout << "\n";
    }
}