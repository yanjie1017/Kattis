#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;

vector<vi> M;
ll r,c,k; 
int a[] = {0,1, 0,-1, 1,0,-1,0};
 
int helper(ll m) { 
    vector<vi> visited; visited.assign(r+1, vi(c+1,0));
    queue<ii> q[k+2]; 
    for (int i=1; i<=c; i++) {
        visited[r][i] = 1;
        if (M[r][i] < m) {
            q[1].emplace(r, i);
        } else {
            q[0].emplace(r, i);
        }
    }
    
    for (int i=0; i<=k; i++) {
        while (!q[i].empty()) {
            ii u = q[i].front(); q[i].pop();
            if (u.first == 1) return 1;

            for (int j=0; j<=6; j+=2) {
                ll rr = u.first + a[j];
                ll cc = u.second + a[j+1];
                if (rr < 1 || cc < 1) continue;
                if (rr >= r || cc > c) continue;
                if (visited[rr][cc]) continue;

                visited[rr][cc] = 1;
                if (M[rr][cc] < m) {
                    q[i+1].emplace(rr,cc);
                } else {
                    q[i].emplace(rr,cc);
                }
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1.in","r",stdin);
    cin >> r >> c >> k;

    ll maxv = 0; 
    M.assign(r+1, vi(c+1,0));
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            cin >> M[i][j];
            maxv = max(maxv, M[i][j]);
        }
    }

    ll L = 0; 
    ll R = maxv;
    ll ans = maxv;
    
    while (L <= R) {
        ll m = (L+R)/2;
        if (helper(m)) {
            ans = m;
            L = m + 1;
        } else {
            R = m - 1;
        }
    }
    cout << ans;
}