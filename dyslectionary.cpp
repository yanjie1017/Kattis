#include <iostream>
#include <iomanip>
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
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;


vector<string> v;

void helper() {
    int maxl = 0;
    for (auto& x:v) {
        maxl = max((int)x.length(), maxl);
        reverse(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto& x:v) {
        reverse(x.begin(), x.end());
    }
    for (auto& x:v) {
        cout << setw(maxl) << x << '\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    string s;
    while(getline(cin, s)) {
        if(s == "") {
            helper();
            cout << '\n';
            v.clear();
            continue;
        }
        v.push_back(s);
    }
    helper(); 
}