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

unordered_map<int, int> row;
unordered_map<int, int> col;
unordered_map<int, int> diag_slash;
unordered_map<int, int> diag_bslash;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int r, c;
        cin >> r >> c;

        row[r]++;
        col[c]++;
        diag_bslash[r+c]++;
        diag_slash[r-c]++;
        if (row[r] > 1 ||
            col[c] > 1 ||
            diag_bslash[r+c] > 1 ||
            diag_slash[r-c] > 1) {
                cout << "INCORRECT";
                return 0;
        }
    }
    cout << "CORRECT";
}