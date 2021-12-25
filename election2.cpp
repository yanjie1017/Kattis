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

    int n; cin >> n; cin.get();
    string name, party;
    unordered_map<string, int> voteM;
    unordered_map<string, string> partyM;
    while (n--) {
        getline(cin, name);
        getline(cin, party);
        partyM[name] = party;
    }
    cin >> n; cin.get();
    int maxVote = 0;
    while (n--) {
        getline(cin, name);
        voteM[name]++;
        maxVote = max(maxVote, voteM[name]);
    }
    vector<string> win;
    for (auto& x:voteM) {
        if (x.second == maxVote) win.push_back(x.first);
    }
    if (win.size() == 1) cout << partyM[win[0]];
    else cout << "tie";
}