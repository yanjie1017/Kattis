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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

unordered_map<ii, ll> visited;
set<ii> row;
set<ii> col;
queue<ii> q;
ll maxX, maxY; 

void fly(ii curr, ) {
    auto itrow = row.find(curr);
    auto itcol = col.find(curr);

    auto left1 = itrow--
    
    for (int i=0; i<2; i++) {

    }
}

void nb(ii curr) {
    fly(curr, vector<char>{'U','U','L'});
    fly(curr, vector<char>{'U','U','R'});
    fly(curr, vector<char>{'D','D','L'});
    fly(curr, vector<char>{'D','D','R'});
    fly(curr, vector<char>{'L','L','U'});
    fly(curr, vector<char>{'L','L','D'});
    fly(curr, vector<char>{'R','R','U'});
    fly(curr, vector<char>{'R','R','D'});
}

void connect() {
    
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    int startX, startY, endX, endY; 
    cin >> startX >> startY >> endX >> endY;

    for (ll i=0; i<n; i++) {
        int a,b; cin >> a >> b;
        row.emplace(a,b);
        col.emplace(b,a);
        visited[ii(a,b)] = 0;
    }

    ll layer = 0;
    ll curr_layer = 1;
    while (!q.empty()) {
        ii curr = q.front(); q.pop(); 
        curr_layer--; 
        if (curr.first == endX && curr.second == endY) {
            cout << layer;
            return 0;
        }
        nb(curr);
        if (curr_layer == 0) {
            curr_layer = q.size();
            layer++;
        }
    }
    cout << -1;
}