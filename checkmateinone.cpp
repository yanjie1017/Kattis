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
#include <utility>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

vector<vector<char>> grid(8, vector<char>());

unordered_set<ii, pair_hash> box(ii k) {
    unordered_set<ii, pair_hash> next_move;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            // if (i == 0 && j == 0) continue;

            int r = k.first + i;
            int c = k.second + j;
            if (r < 0 || c < 0) continue;
            if (r >= 8 || c >= 8) continue;
            next_move.emplace(r,c);
        }
    }
    return next_move;
}

void king(ii K, unordered_set<ii, pair_hash>& next_move) {
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int r = K.first + i;
            int c = K.second + j;
            if (r < 0 || c < 0) continue;
            if (r >= 8 || c >= 8) continue;
            // if (grid[r][c] != '.') continue;
            next_move.erase(ii(r,c));
        }
    }
}

void root(ii R, unordered_set<ii, pair_hash>& next_move) {
    for (int i=R.first-1; i>=0; i--) {
        if (grid[i][R.second] != '.') break;
        next_move.erase(ii(i,R.second));
    }
    for (int i=R.first+1; i<8; i++) {
        if (grid[i][R.second] != '.') break;
        next_move.erase(ii(i,R.second));
    }
    for (int j=R.second-1; j>=0; j--) {
        if (grid[R.first][j] != '.') break;
        next_move.erase(ii(R.first,j));
    }
    for (int j=R.second+1; j<8; j++) {
        if (grid[R.first][j] != '.') break;
        next_move.erase(ii(R.first,j));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ii k, K, R;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            char x; cin >> x;
            grid[i].push_back(x);
            if (x == 'k') k = ii(i,j);
            if (x == 'K') K = ii(i,j);
            if (x == 'R') R = ii(i,j);
        }
    }
    grid[k.first][k.second] = '.';

    unordered_set<ii, pair_hash> next_move = box(k);

    unordered_set<ii, pair_hash> temp1 = next_move;
    grid[R.first][R.second] = '.';
    grid[R.first][k.second] = 'R';
    root(ii(R.first, k.second), temp1);
    king(K, temp1);
    if (temp1.empty()) {cout << "Yes" << endl; return 0;}
    grid[R.first][R.second] = 'R';
    grid[R.first][k.second] = '.';

    unordered_set<ii, pair_hash> temp2 = next_move;
    grid[R.first][R.second] = '.';
    grid[k.first][R.second] = 'R';
    root(ii(k.first, R.second), temp2);
    king(K, temp2);
    if (temp2.empty()) {cout << "Yes" << endl; return 0;}

    cout << "No" << endl;
}