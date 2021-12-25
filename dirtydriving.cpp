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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());

    int d = 0;
    for(int i=0; i<v.size(); i++) {
        d = max(p*(i+1) - v[i], d);
    }
    cout << d + v[0] << endl;
}