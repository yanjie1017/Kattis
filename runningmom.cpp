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

unordered_map<string, vector<string>> AL;
unordered_map<string, int> visited;

bool isCycle;
void dfs(string i) {
    visited[i] = 1;
    for (auto& x:AL[i]) {
        if (visited[x] == 1) isCycle = true;
        if (!visited[x]) dfs(x);
    } 
    visited[i] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mom.in","r",stdin);

    int n; cin >> n;
    

    while (n--) {
        string a,b; cin >> a >> b;
        AL[a].push_back(b); 
    }

    string s;
    while (cin >> s) {
        isCycle = false;
        cout << s << " ";
        dfs(s);
        if (isCycle) cout << "safe" << endl;
        else cout << "trapped" << endl;
        visited.clear();    
    }
}