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
typedef vector<ll> vi;

vector<vector<char>> M;
queue<ii> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m; cin >> n >> m;
    M.assign(n, vector<char>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char x; cin >> x;
            M[i][j] = x;
            if (x == 'V') {
                q.emplace(i,j);
            }
        }
    }

    while (!q.empty()) {
        int ui = q.front().first; int uj = q.front().second; 
        q.pop();
        if (ui + 1 < n) {
            if (M[ui+1][uj] == '.') {
                M[ui+1][uj] = 'V';
                q.emplace(ui+1,uj);
            }
            if (M[ui+1][uj] == '#') {
                if (uj-1 >= 0 && M[ui][uj-1] == '.') {
                    M[ui][uj-1] = 'V';
                    q.emplace(ui,uj-1);
                }
                if (uj+1 < m && M[ui][uj+1] == '.') {
                    M[ui][uj+1] = 'V';
                    q.emplace(ui,uj+1);
                }
            }
        }     
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << M[i][j];
        }
        cout << '\n';
    }
}