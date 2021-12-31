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

vi visited;
int v_ind;

int dfs (int u, vector<vi>& AL) {
    if (visited[u] == v_ind) return 0;
    visited[u] = v_ind;
    int total = 1;
    for (auto& v:AL[u]) {
        total += dfs(v,AL);
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int A,B,E,P; 
    while (cin >> A >> B >> E >> P) {
        vector<vi> AL; AL.assign(E, vi());
        vector<vi> INV_AL; INV_AL.assign(E, vi());
        visited.assign(E,0);

        while (P--) {
            int x,y; cin >> x >> y;
            AL[x].emplace_back(y);
            INV_AL[y].emplace_back(x);
        }

        int a=0, b=0, c=0;
        v_ind = 0;
        for (int i=0; i<E; i++) {
            v_ind++;
            int worse = dfs(i,AL)-1;
            int inrange = E - worse;
            v_ind++;
            int better = dfs(i, INV_AL);

            if (inrange <= A) a++;
            if (inrange <= B) b++;
            if (better > B) c++;
        }
        cout << a << endl << b << endl << c << endl;
    }
}