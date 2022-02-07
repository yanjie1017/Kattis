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
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

vector<vector<int>> V;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n,m; cin >> n >> m;
    V.assign(n, vector<int>(m,0));
    A.assign(m,0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char x; cin >> x;
            if (x == 'T') V[i][j] = 1;
        }
    }
    
    int max_score = 0;
    for (int k=m; k>=0; k--) {
        sort(A.begin(), A.end());
        if (k != m) A[k] = 1;
        do {
            int min_score = m;
            for (int i=0; i<n; i++) {
                int sub_total = 0;
                for (int j=0; j<m; j++) {
                    if (V[i][j] == A[j]) sub_total++;
                }
                min_score = min(min_score, sub_total);
            }
            max_score = max(max_score, min_score);
        } while (next_permutation(A.begin(), A.end()));
    }

    cout << max_score;
}
