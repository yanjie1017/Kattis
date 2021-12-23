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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    unordered_set<string> s;

    string curr, prev; cin >> curr; 
    s.insert(curr); prev = curr;
    for (int i=1; i<n; i++) {
        cin >> curr;
        if (curr[0] != prev[prev.length()-1] || 
        s.find(curr) != s.end()) {
            int player;
            if (i % 2 == 0) player = 1;
            else player = 2;
            cout << "Player " << player << " lost";
            return 0;
        }
        prev = curr;
        s.insert(prev);
    }
    cout << "Fair game";
}