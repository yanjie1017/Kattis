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

using ll = long long;
using ii = pair<ll,ll>;

vector<vector<char>> MAP;
priority_queue<ll> Q;
ll h,n,m; 

ll nb(int r, int c) {
    ll cnt = 1;
    for (int i=-1; i<=1; i++) {
        int cc = c + i;
        if (cc < 0 || cc >= m) continue;
        if (MAP[r][cc] == '#') continue;
        MAP[r][cc] = '#';
        cnt += nb(r,cc);
    }

    int i, iend;
    if (r%2) i = 0; 
    else i = -1;
    iend = i+2;
    for (; i < iend; i++) {
        for (int j = -1; j < 2; j += 2) {
            int rr = r+j;
            int cc = c+i;
            if (rr < 0 || rr >= n) continue;
            if (cc < 0 || cc >= m) continue;
            if (MAP[rr][cc] == '#') continue;
            MAP[rr][cc] = '#';
            cnt += nb(rr,cc);
        }
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    cin >>  h >>n >> m;
    MAP.assign(n, vector<char>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (MAP[i][j] == '.') {
                MAP[i][j] = '#';
                ll c = nb(i,j);
                Q.push(c);
            }
        }
    }

    ll ans = 0;
    while (h>0) {
        h -= Q.top();
        Q.pop();
        ans++;
    }

    cout << ans;
}