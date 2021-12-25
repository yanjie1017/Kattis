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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    string n; int day = 0;
    map<string, int> total;
    map<string, int> record;
    while (cin >> n) {
        
        if (n == "OPEN") {
            day++;
            continue;
        } 
        if (n == "ENTER") {
            string name; int x; cin >> name >> x;
            record[name] = x;
            continue;
        } 
        if (n == "EXIT") {
            string name; int x; cin >> name >> x;
            total[name] += x - record[name];
            continue;
        } 
        if (n == "CLOSE") {
            cout << "Day " << day << '\n';
            for (auto& x:total) {
                cout << fixed << setprecision(2);
                cout << x.first << " $" << x.second * 0.1 << endl;
            }
            total.clear();
            record.clear();
            cout << '\n';
        } 
    }
}