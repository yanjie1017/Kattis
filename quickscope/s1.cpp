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

vector<unordered_map<string, string>> db;
stack<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in","r",stdin);

    int n; cin >> n;
    int level = 0;

    db.assign(n/2+1, unordered_map<string, string>());

    while (n--) {
        string c; cin >> c;
        if (c == "DECLARE") {
            string m, type; cin >> m >> type;
            if (db[level].find(m) != db[level].end()) {
                cout << "MULTIPLE DECLARATION\n"; return 0;
            }
            else {
                db[level][m] = type;
            }
        }
        if (c == "TYPEOF") {
            string m; cin >> m;
            bool isDeclared = false;
            for (int i=level; i >= 0; i--) {
                if (db[i].find(m) != db[i].end()) {
                    cout << db[i][m] << "\n";
                    isDeclared = true;
                    break;
                }
            }
            if (!isDeclared) cout << "UNDECLARED\n"; 
        }
        if (c == "{") {
            level++;
            s.push(c);
        }
        if (c == "}") {
            s.pop();
            db[level].clear();
            level--;
        }
    }
}