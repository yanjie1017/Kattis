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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

template<class T>
using ordered_set = tree<
        T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;

int inversion_index(vi& V) {
    int x = 0;
    ordered_set<int> S;
    for (int i=1; i<=V.size(); i++) {
        S.insert(i);
    }
    for (int i=0; i<V.size(); i++) {
        x += S.order_of_key(V[i]);
        S.erase(V[i]);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; 
    cin >> n;
    vi v1(n), v2(n);
    for (auto& x:v1) {
        cin >> x;
    }
    for (auto& x:v2) {
        cin >> x;
    }

    int a = inversion_index(v1);
    int b = inversion_index(v2);
    int c = abs(a-b);
    if (c % 2 == 0) cout << "Possible";
    else cout << "Impossible";
}
