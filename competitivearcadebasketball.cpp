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

    unordered_map<string, int> scoreboard;
    unordered_set<string> won;
    int n, p, m; cin >> n >> p >> m;
    while (n--) {
        string name; cin >> name;
        scoreboard[name] = 0;
    }
    while (m--) {
        string name; int score; cin >> name >> score;
        scoreboard[name] += score;
        if (won.find(name) == won.end() && scoreboard[name] >= p) {
            cout << name << " wins!\n";
            won.insert(name);
        }
    }
    if (won.empty()) cout << "No winner!";
}