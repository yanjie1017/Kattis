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
    freopen("1.in","r",stdin);

    int n; cin >> n;
    vector<int> v; v.assign(n, 0);
    int arrow = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        if (v[i] == 0) continue;
        int step = 1; int height = v[i]-1;
        while (i+step < v.size()) {
            if (height == 0) break;
            if (v[i+step] == height) {
                v[i+step]=0;
                height--;
            }
            step++;
        }
        v[i] = 0;
        arrow++;
    }
    cout << arrow;
}