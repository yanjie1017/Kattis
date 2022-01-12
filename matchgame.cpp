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
typedef vector<ii> vii;

unordered_map<char, vector<int>> M = {
    {'0', {1,1,1,1,1,1,0}},
    {'1', {0,0,0,0,1,1,0}},
    {'2', {1,0,1,1,0,1,1}},
    {'3', {1,0,0,1,1,1,1}},
    {'4', {0,1,0,0,1,1,1}},
    {'5', {1,1,0,1,1,0,1}},
    {'6', {1,1,1,1,1,0,1}},
    {'7', {1,0,0,0,1,1,0}},
    {'8', {1,1,1,1,1,1,1}},
    {'9', {1,1,0,1,1,1,1}}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    string s1, s2; cin >> s1 >> s2; 
    int move = 0; int dff = 0; 
    for (int i=0; i<s1.length(); i++) {
        if (s1[i] == s2[i]) continue;
        for (int j=0; j<7; j++) {
            if (M[s1[i]][j] >  M[s2[i]][j]) {
                move++;
                dff--;
            }
            if (M[s1[i]][j] <  M[s2[i]][j]) {
                move++;
                dff++;
            }
        }
    }

    if (dff == 0 && move == 2) {
        cout << "yes";
    } else {
        cout << "no";
    }
}