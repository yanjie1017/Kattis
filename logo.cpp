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
typedef vector<int> vi;

double pi = M_PI;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int tc; cin >> tc;
    while (tc--) {
        double x = 0; double y = 0; int angle = 0;

        int n, v; string s; cin >> n;
        while (n--) {
            cin >> s >> v;

            if (s == "fd") {
                x += v * cos(angle * (pi / 180));
                y += v * sin(angle * (pi / 180));
            }
            if (s == "bk") {
                x -= v * cos(angle * (pi / 180));
                y -= v * sin(angle * (pi / 180));
            }
            if (s == "lt") {
                angle += v;
            }
            if (s == "rt") {
                angle -= v;
            }
        }

        int d = round(sqrt(pow(x,2)+pow(y,2)));
        cout << d << endl;
    }
}