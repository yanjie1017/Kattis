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

int x;
int helper(vector<int> A, vector<int> B) {
    int maxS = 0;
    int i = 1; int j = 100;
    int cnt = 0;
    while (true) {
        if (cnt == x) break;
        while (A[i] == 0) {
            i++;    
        }
        while (B[j] == 0) {
            j--; 
        }
        maxS = max(maxS, i+j);
        int intersect = min(A[i], B[j]);
        A[i] -= intersect;
        B[j] -= intersect;
        cnt += intersect;
    }
    return maxS;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    vector<int> A(101,0);
    vector<int> B(101,0);
    int n; cin >> n; int maxN = 0;
    for (x=1; x<=n; x++) {
        int a, b; cin >> a >> b;
        A[a]++; B[b]++;
        cout << helper(A,B) << endl;
    }
}
