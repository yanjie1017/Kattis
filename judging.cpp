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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    unordered_map<string,int> judge;
    unordered_map<string,int> kattis;
    unordered_set<string> record;
    for (int i=0; i<n; i++) {
        string x; cin >> x;
        judge[x]++;
        record.insert(x);
    }
    for (int i=0; i<n; i++) {
        string x; cin >> x;
        kattis[x]++;
        record.insert(x);
    }
    int total = 0;
    for (auto& x:record) {
        total += min(judge[x],kattis[x]);
    }
    cout << total;
}