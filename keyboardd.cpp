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

    string a, b;
    getline(cin, a);
    getline(cin, b);
    unordered_map<char, int> A;
    unordered_map<char, int> B;
    set<char> record;
    for (auto& x:a) {
        A[x]++;
        record.insert(x);
    }
    for (auto& x:b) {
        B[x]++;
    }
    for (auto& x:record) {
        if (A[x] != B[x]) cout << x;
    }
}