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

unordered_map<int, int> need;
unordered_map<int, int> supplied;
vector<vector<ii>> AL;
vector<int> collapsed;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("collapse.in","r",stdin);

    int n; cin >> n;
    AL.assign(n+1, vector<ii>());
    collapsed.assign(n+1, 0);

    for (int i=1; i<=n; i++) {
        cin >> need[i]; 
        int t; cin >> t;
        while (t--) {
            int v, w; cin >> v >> w;
            AL[v].push_back(ii(i,w));
            supplied[i] += w;
        }
    }

    collapsed[1] = 1;
    q.push(1); n--;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (auto& x:AL[curr]) {
            int xi = x.first;
            if (!collapsed[xi]) {
                supplied[xi] -= x.second;
                if (supplied[xi] < need[xi]) {
                    collapsed[xi] = 1;
                    q.push(xi);
                    n--;
                }
            }
        }   
    }
    cout << n;  
}