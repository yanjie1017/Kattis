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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("pivot.in","r",stdin);

    vi arr, mm, oo;
    int n; cin >> n;
    int m; cin >> m;
    arr.push_back(m); mm.push_back(m);
    n--;
    while (n--) {
        int i; cin >> i;
        m = max(i, m); 
        arr.push_back(i); mm.push_back(m);
    }
    int count = 0;
    int o = arr.back(); oo.assign(arr.size(),0);
    for (int i=arr.size()-1; i>=0; i--) {
        o = min(o, arr[i]);
        oo[i] = o;
        if (arr[i] >= mm[i] && arr[i] <= oo[i]) count++;
    }
    cout << count;
}