#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<string, int> v;

int main() {
    //freopen("2.in","r",stdin);
    int n; cin >> n;
    unordered_map<int, v> db;
    set<string> names;
    while (n--) {
        string name, bday; int p, date;
        cin >> name >> p >> bday;

        date = stoi(bday.substr(0,2)) *100 + stoi(bday.substr(3,2));
        auto found = db.find(date);

        if (found == db.end()) {
            db.emplace(date, v(name, p));
            names.emplace(name);
        } else {
            if (p > db[date].second) {
                names.erase(db[date].first);
                db[date] = v(name, p);
                names.emplace(name);
            }
        }
    }
    cout << names.size() << "\n";
    auto i=names.begin(); 
    while (i != names.end()) {
        cout << *i << "\n";
        i++;
    }
    return 0;
}