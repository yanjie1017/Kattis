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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n;
    cin >> n >> n;

    for(int i=1; i<=n; i++) {
        string x; int j=i;
        while (j>0) {
            x.push_back('a' + j%26);
            j /= 26;
        }
        cout << x << ' ';
    }
    cout << endl;
}
