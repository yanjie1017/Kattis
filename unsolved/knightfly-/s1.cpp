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

vector<vi> visited;
queue<ii> q;
ll maxX, maxY; 

void sub(ii start, vector<char> seq) {
    bool found = true;
    ll xx = start.first; 
    ll yy = start.second;
    for (int i=0; i<3; i++) {
        switch (seq[i]) {
            case 'U':
                while (true) {
                    xx -= 1;
                    if (xx <= 0 || xx > maxX) return;
                    if (!visited[xx][yy]) {
                        found = true; break;
                    } 
                }
                break;
            case 'D':
                while (true) {
                    xx += 1;
                    if (xx <= 0 || xx > maxX) return;
                    if (!visited[xx][yy]) {
                        found = true; break;
                    } 
                }
                break;
            case 'R':
                while (true) {
                    yy += 1;
                    if (yy <= 0 || yy > maxY) return;
                    if (!visited[xx][yy]) {
                        found = true; break;
                    } 
                }
                break;
            case 'L':
                while (true) {
                    yy -= 1;
                    if (yy <= 0 || yy > maxY) return;
                    if (!visited[xx][yy]) {
                        found = true; break;
                    } 
                }
                break;
        }
        if (!found) return;
    }
    visited[xx][yy] = 1;
    q.push(ii(xx,yy));
}
void nb(ii curr) {
    sub(curr, vector<char>{'U','U','L'});
    sub(curr, vector<char>{'U','U','R'});
    sub(curr, vector<char>{'D','D','L'});
    sub(curr, vector<char>{'D','D','R'});
    sub(curr, vector<char>{'L','L','U'});
    sub(curr, vector<char>{'L','L','D'});
    sub(curr, vector<char>{'R','R','U'});
    sub(curr, vector<char>{'R','R','D'});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("knightfly.in","r",stdin);

    int n; cin >> n;
    int startX, startY, endX, endY; 
    cin >> startX >> startY >> endX >> endY;

    maxX = max(startX, endX)+1;
    maxY = max(startY, endY)+1;
    q.push(ii(startX,startY));
    visited.assign(maxX, vi(maxY,1));

    for (ll i=0; i<n; i++) {
        int a,b; cin >> a >> b;
        if (a > maxX || b > maxY) continue; //WA
        visited[a][b] = 0;
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