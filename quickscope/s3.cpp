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

unordered_map<string, stack<pair<int, string>>> db;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    int level = 0; int track = level;
    s.push(track);

    while (n--) {
        string c; cin >> c;
        if (c == "DECLARE") {
            string m, type; cin >> m >> type;
            if (db.find(m) == db.end()) {
                db[m] = stack<pair<int, string>>();
                db[m].push(pair<int, string>(level, type));
            } else {
                while (!db[m].empty() && db[m].top().first > level) {
                    db[m].pop();
                }
                if (!db[m].empty() && db[m].top().first == level) {
                    cout << "MULTIPLE DECLARATION\n"; return 0;
                } else {
                    db[m].push(pair<int, string>(level, type));
                }
            }
        }
        if (c == "TYPEOF") {
            string m; cin >> m;
            if (db.find(m) == db.end()) {
                cout << "UNDECLARED\n"; 
            } else {
                stack<int> temp = s;
                bool isDeclared = false;
                while (!db[m].empty() && db[m].top().first > level) {
                    db[m].pop();
                }
                while (!db[m].empty() && !temp.empty()) {
                    if (db[m].top().first == temp.top()) {
                        isDeclared = true;
                        cout << db[m].top().second << "\n"; break;
                    } else if (db[m].top().first > temp.top()) {
                        db[m].pop();
                    } else {
                        temp.pop();
                    }
                }
                if (!isDeclared) cout << "UNDECLARED\n";
            } 
        }
        if (c == "{") {
            track++; 
            level = track;
            s.push(track);
        }
        if (c == "}") {
            s.pop(); 
            level = s.top();
        }
    }
}