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

vector<vi> visited;
queue<ii> q;
int R,C,sr,sc,er,ec; 

vector<ii> nb(int r, int c) {
    vector<ii> v;
    vi dr = {+2,+2,-2,-2,+1,+1,-1,-1};
    vi dc = {+1,-1,+1,-1,+2,-2,+2,-2};
    
    for (int i=0; i<8; i++) {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 || cc < 0) continue;
        if (rr >= R || cc >= C) continue;
        v.emplace_back(rr,cc);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    while (cin >> R >> C >> sr >> sc >> er >> ec) {
        sr--; sc--; er--; ec--;
        visited.assign(R, vector<int>(C,0));

        queue<ii> q;
        q.emplace(sr,sc);
        bool arrived = false;
        while (!q.empty()) {
            int ur = q.front().first;
            int uc = q.front().second;
            int us = visited[ur][uc];
            q.pop();
            if (ur == er && uc == ec) {
                arrived = true;
                break;
            }
            for (auto& [vr,vc]:nb(ur,uc)) {
                if (visited[vr][vc]) continue;
                visited[vr][vc] = us+1;
                q.emplace(vr,vc);
            }
        }
        if (arrived) cout << visited[er][ec] << endl;
        else cout << "impossible" << endl;
    }  
}