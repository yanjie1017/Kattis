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

    int r, c; cin >> r >> c;
    vector<vector<char>> grid; grid.assign(c,vector<char>(r,0));

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> grid[j][i];
        }
    }
    for (int i=0; i<c; i++) {
        bool swap;
        do {
            swap = false;
            for (int j=0; j<r-1; j++) {
                if (grid[i][j] == 'a' && grid[i][j+1] == '.') {
                    grid[i][j] = '.';
                    grid[i][j+1] = 'a';
                    swap = true;
                }
            }
        } while (swap);
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << grid[j][i];
        }
        cout << '\n';
    }
}