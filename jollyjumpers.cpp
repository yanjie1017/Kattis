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

    int n;
    while (cin >> n) {
        unordered_set<int> s;
        int a, b; cin >> a;
        for (int i=1; i<n; i++) {
            cin >> b;
            if (abs(a-b) > 0 && abs(a-b) < n) s.insert(abs(a-b));
            a = b;
        }
        if (s.size() >= n-1) cout << "Jolly\n";
        else cout << "Not Jolly\n";
    }
}