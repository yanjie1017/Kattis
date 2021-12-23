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
vi cost_so_far;
vector<vector<ii>> AL;
int n;

void BFS(int i) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push(ii(0,1));
    while (!q.empty()) {
        int curr_i = q.top().second; 
        int curr_p = q.top().first;
        q.pop();
        for (auto& x:AL[curr_i]) {
            int i = x.second; 
            int p = x.first + curr_p;
            if (!visited[i] || curr_p < cost_so_far[i]) {
                visited[i] = 1;
                cost_so_far[i] = p;
                q.push(ii(p,i));
            }
        }       
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("bridge.in","r",stdin);

    int m; cin >> n >> m;
    visited.assign(n+1,0);
    cost_so_far.assign(n+1,0);
    AL.assign(n+1, vector<ii>());

    while (m--) {
        int a,b,c; cin >> a >> b >> c;
        AL[a].push_back(ii(c,b));
        AL[b].push_back(ii(c,a));
    }

    BFS(1);
    cout << cost_so_far[n];
}