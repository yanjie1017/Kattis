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

    string n; int maxVote = 0;
    unordered_map<string, int> M;
    while (getline(cin, n)) {
        if (n == "***") break;
        M[n]++;
        maxVote = max(maxVote, M[n]);
    }
    vector<string> win;
    for (auto& x:M) {
        if (x.second == maxVote) win.push_back(x.first);
    }
    if (win.size() == 1) cout << win[0];
    else cout << "Runoff!";
}