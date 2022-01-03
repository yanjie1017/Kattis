#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, string> pp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in","r",stdin);
    int n; cin >> n;
    auto cmp = [](pp a, pp b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    };
    set<pp, decltype(cmp)> s1(cmp), s2(cmp), s3(cmp);
    unordered_map<string, vector<ll>> db;
    vector<set<string>> output;

    while (n--) {
        string name; ll p1, p2, p3;
        cin >> name >> p1 >> p2 >> p3;
        s1.emplace(pp(p1, name)); s2.emplace(pp(p2, name)); s3.emplace(pp(p3, name));
        db.emplace(name, vector<ll> {p1,p2,p3});
    }
    set<string> s;
    while (true) {
        string p1, p2, p3;
        if (s1.empty()) break;
        p1 = (*s1.begin()).second;
        s1.erase(pp(db[p1][0],p1)); s2.erase(pp(db[p1][1],p1)); s3.erase(pp(db[p1][2],p1)); 
        if (s2.empty()) break;
        p2 = (*s2.begin()).second;
        s1.erase(pp(db[p2][0],p2)); s2.erase(pp(db[p2][1],p2)); s3.erase(pp(db[p2][2],p2)); 
        if (s3.empty()) break;
        p3 = (*s3.begin()).second;
        s1.erase(pp(db[p3][0],p3)); s2.erase(pp(db[p3][1],p3)); s3.erase(pp(db[p3][2],p3)); 
        s.emplace(p1); s.emplace(p2); s.emplace(p3);
        output.push_back(s);
        s.clear();
    }
    for (auto& elem : output) {
        cout << *elem.begin() << " " << *(++elem.begin()) << " " << *(++(++elem.begin())) << "\n";
    }
}