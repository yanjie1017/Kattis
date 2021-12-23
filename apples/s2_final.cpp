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
        int start = 0; int end;
        int j = 0; 
        while (j<r) {
            if (grid[i][j] == '#') {
                end = j;
                sort(grid[i].begin()+start, grid[i].begin()+end);
                start = end+1;
            }
            j++;
        }
        sort(grid[i].begin()+start, grid[i].end());
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << grid[j][i];
        }
        cout << '\n';
    }
}