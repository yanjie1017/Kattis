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

const unordered_map<char, ii> ADDR = {
    {'A', {0,0}},
    {'B', {0,1}},
    {'C', {0,2}},
    {'D', {0,3}},
    {'E', {0,4}},
    {'F', {1,0}},
    {'G', {1,1}},
    {'H', {1,2}},
    {'I', {1,3}},
    {'J', {1,4}},
    {'K', {2,0}},
    {'L', {2,1}},
    {'M', {2,2}},
    {'N', {2,3}},
    {'O', {2,4}},
    {'P', {3,0}},
    {'Q', {3,1}},
    {'R', {3,2}},
    {'S', {3,3}},
    {'T', {3,4}},
    {'U', {4,0}},
    {'V', {4,1}},
    {'W', {4,2}},
    {'X', {4,3}},
    {'Y', {4,4}},
};



void up(char s, vector<vector<char>>& grid, unordered_map<char, ii>& addr) {
    int x = addr[s].first; int y = addr[s].second; 
    int b;
    for (int i=x-1; x>=0; i--) {
        if (grid[i][y] == '.') {
            b=i; break;
        }
    }
    for (int i=b; i<x; i++) {
        grid[i][y] = grid[i+1][y];
        if (grid[i][y] != '.') addr[grid[i][y]] = ii(i,y);
    }
    grid[x][y] = '.';
}
void down(char s, vector<vector<char>>& grid, unordered_map<char, ii>& addr) {
    int x = addr[s].first; int y = addr[s].second; 
    int b;
    for (int i=x+1; x<105; i++) {
        if (grid[i][y] == '.') {
            b=i; break;
        }
    }
    for (int i=b; i>x; i--) {
        grid[i][y] = grid[i-1][y];
        if (grid[i][y] != '.') addr[grid[i][y]] = ii(i,y);
    }
    grid[x][y] = '.';
}
void left(char s, vector<vector<char>>& grid, unordered_map<char, ii>& addr) {
    int x = addr[s].first; int y = addr[s].second; 
    int b;
    for (int i=y-1; y>=0; i--) {
        if (grid[x][i] == '.') {
            b=i; break;
        }
    }
    for (int i=b; i<y; i++) {
        grid[x][i] = grid[x][i+1];
        if (grid[x][i] != '.') addr[grid[x][i]] = ii(x,i);
    }
    grid[x][y] = '.';
}
void right(char s, vector<vector<char>>& grid, unordered_map<char, ii>& addr) {
    int x = addr[s].first; int y = addr[s].second; 
    int b;
    for (int i=y+1; y<105; i++) {
        if (grid[x][i] == '.') {
            b=i; break;
        }
    }
    for (int i=b; i>y; i--) {
        grid[x][i] = grid[x][i-1];
        if (grid[x][i] != '.') addr[grid[x][i]] = ii(x,i);
    }
    grid[x][y] = '.';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n;
    while (cin >> n) {
        if (n == -1) return 0;

        unordered_map<char, ii> addr = ADDR;
        vector<vector<char>> grid; grid.assign(105, vector<char>(105,'.'));
        int minX = 50; int minY = 50;
        int maxX = 54; int maxY = 54;
        
        for (char i='A'; i<'Z'; i++) {
            addr[i].first += minX;
            addr[i].second += minY;
            grid[addr[i].first][addr[i].second] = i;
        }
        
        while (n--) {
            char x; string command; cin >> x >> command;
            if (command == "left") left(x, grid, addr);
            if (command == "right") right(x, grid, addr);
            if (command == "up") up(x, grid, addr);
            if (command == "down") down(x, grid, addr);
        }

        for (int i=0; i<105; i++) {
            for (int j=0; j<105; j++) {
                if (grid[i][j] == '.') continue;
                minX = min(minX, i); maxX = max(maxX, i);
                minY = min(minY, j); maxY = max(maxY, j); 
            }
        }

        vi endY = vi(105,0);
        for (int i=minX; i<=maxX; i++) {
            for (int j=minY; j<=maxY; j++) {
                if (grid[i][j] == '.') continue;
                endY[i] = j;
            }
        }
        for (int i=minX; i<=maxX; i++) {
            for (int j=minY; j<=endY[i]; j++) {
                if (grid[i][j] == '.') cout << ' ';
                else cout << grid[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}