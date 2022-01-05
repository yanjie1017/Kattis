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
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    
    vector<unordered_map<int,int>> M;
    M.assign(20, unordered_map<int,int>());
    set<int> S;

    int c,k,n,d;
    cin >> c;
    for (int i=0; i<c; i++) {
        cin >> k;
        while (k--) {
            cin >> n >> d;
            if (n == 0) continue;
            S.insert(d);
            M[i][d] = n;
        }
    }

    vector<int> V(20,0);
    for (auto& d:S) {
        int total = 0;
        for (int i=0; i<c; i++) {
            if (M[i][d] == 0) {
                total += V[i];
                continue;
            }
            V[i] = M[i][d];
            total += V[i];
        }
        cout << total << ' ';
    }
}