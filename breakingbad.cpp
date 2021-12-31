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
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<string> V;
unordered_map<string, int> M;
unordered_map<string, vector<string>> AL;
bool impossible = false;

void bfs(string x) {
    queue<string> q;
    q.push(x);
    M[x] = 1;

    while (!q.empty()) {
        string u = q.front(); q.pop();
        int ui = M[u];
        int vi = 2;
        if (ui == 2) vi = 1;

        for (auto& v:AL[u]) {
            if (M[v]) {
                if (M[v] == ui) {impossible = true; return; }
                continue;
            }
            M[v] = vi;
            q.push(v);
        }       
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m; string s,a,b;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s; V.emplace_back(s);
    }
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> a >> b; 
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    for (auto& x:V) {
        if (M[x] != 0) continue;
        bfs(x);
        if (impossible) {
            cout << "impossible"; return 0;
        }
    }

    vector<string> v1, v2;
    for (auto& x:V) {
        if (M[x] == 1) v1.push_back(x);
        else v2.push_back(x);
    }
    for (auto& x:v1) {
        cout << x << ' ';
    }
    cout << endl;
    for (auto& x:v2) {
        cout << x << ' ';
    }
}