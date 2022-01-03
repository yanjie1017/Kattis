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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("smil.in","r",stdin);
    string n; cin >> n;
    int i=0;
    while (i<n.length()) {
        if (n[i] != ':' && n[i] != ';') {
            i++; continue;
        }
        if (n[i+1] == ')') {
            cout << i << '\n';
            i += 2;
            continue;
        }
        if (n[i+1] == '-' && n[i+2] == ')') {
            cout << i << '\n';
            i += 3;
            continue;
        }
        i++;
    }
