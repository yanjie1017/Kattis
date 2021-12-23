#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
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

    int n; cin >> n; 
    
    while (n--) {
        queue<int> left;
        queue<int> right;
        int L, m; cin >> L >> m;
        L *= 100; //in cm

        while (m--) {
            int l; string side; cin >> l >> side;
            if (side == "left") left.push(l);
            else right.push(l);
        }

        int step = 0;
        bool isLeft = true;
        while (!left.empty() || !right.empty()) {
            int totalL = 0;
            if (isLeft) {
                while (!left.empty() && left.front() + totalL <= L) {
                    totalL += left.front();
                    left.pop();
                }
                isLeft = false;
            } else {
                while (!right.empty() && right.front() + totalL <= L) {
                    totalL += right.front();
                    right.pop();
                }
                isLeft = true;
            }
            step++;
        }
        cout << step << endl;
    }
    
}
