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

    int queens = 0;
    for (int r=0; r<8; r++) {
        for (int c=0; c<8; c++) {
            char x; cin >> x;
            if (x == '.') continue;
            
            queens++;
            row[r]++;
            col[c]++;
            diag_bslash[r+c]++;
            diag_slash[r-c]++;
            if (row[r] > 1 ||
                col[c] > 1 ||
                diag_bslash[r+c] > 1 ||
                diag_slash[r-c] > 1) {
                    cout << "invalid";
                    return 0;
            }
        }
    }
    if(queens == 8) {
        cout << "valid";
    }
    else {
        cout << "invalid";
    }
}