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
#include <utility>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;

unordered_map<string, vector<string>> AL;
unordered_map<string, int> visited;
stack<string> tps;

void dfs(string s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto& x : AL[s]) {
        if (!visited[x]) dfs(x);
    }
    tps.push(s); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n; cin.get();
    
    while (n--) {
        string input, file, s;
        getline(cin, input);
        stringstream ss(input);
        ss >> file; file = file.substr(0, file.length()-1);

        while (ss >> s) {
            AL[s].emplace_back(file);
        }
    }

    string start; cin >> start;
    dfs(start);
    while (!tps.empty()) {
        cout << tps.top() << endl; tps.pop();
    }
}