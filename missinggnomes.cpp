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
    //freopen("gnome.in","r",stdin);

    queue<int> remain;
    map<int, int> check;
    int n, r; cin >> n >> r;
    while (r--) {
        int t; cin >> t; remain.push(t); check[t] = 1;
    }
    int i=1;
    while (!remain.empty()) {
        if (i < remain.front()) {
            if (check[i]) {
                i++; continue;
            } else {
                cout << i << '\n';
                i++; continue;
            }
        } else if (i == remain.front()) {
            cout << remain.front() << '\n';
            remain.pop();
            i++; continue;
        } else {
            cout << remain.front() << '\n';
            remain.pop(); continue;
        }
    }
    while (i <= n) {
        cout << i++ << '\n';
    }
}