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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    char n;
    vector<int> V(11);
    while (cin >> n) {
        V[n-'0']++;
    }
    V[10] = V[0];

    int ans = 1;
    int cnt = V[1];
    for(int i = 1; i <= 10; i++) {
        if (V[i] < cnt) {
            cnt = V[i];
            ans = i;
        } 
    }
    if (ans == 10) {
        cout << 1;
        ans = 0;
    }
    for (int i=0; i<cnt+1; i++) {
        cout << ans;
    }
}
