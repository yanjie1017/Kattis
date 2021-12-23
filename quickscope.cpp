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

unordered_map<string, unordered_map<int, string>> db;
unordered_map<string, vector<int>> lvl;
vector<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    int level = 0; int track = level;
    s.push_back(level);

    while (n--) {
        string c; cin >> c;
        if (c == "DECLARE") {
            string m, type; cin >> m >> type;
            if (db.find(m) == db.end()) {
                db[m] = unordered_map<int, string>();
                lvl[m] = vector<int>();
            } else if (db[m].find(level) != db[m].end()) {
                cout << "MULTIPLE DECLARATION\n"; return 0;
            } 
            db[m][level] = type;
            lvl[m].push_back(level);
        }
        if (c == "TYPEOF") {
            string m; cin >> m;
            if (db.find(m) == db.end()) {
                cout << "UNDECLARED\n"; 
            } else {
                bool isDeclared = false;
                while (!lvl[m].empty()) {
                    if (binary_search(s.begin(), s.end(), lvl[m].back())) {
                        isDeclared = true;
                        cout << db[m][lvl[m].back()] << "\n"; break;
                    } else {
                        lvl[m].pop_back(); continue;
                    }
                }
                if (!isDeclared) cout << "UNDECLARED\n";
            } 
        }
        if (c == "{") {
            track++; 
            level = track;
            s.push_back(track);
        }
        if (c == "}") {
            s.pop_back(); 
            level = s.back();
        }
    }
}