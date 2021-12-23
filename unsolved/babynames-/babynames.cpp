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
typedef vector<int> vi;

unordered_map<int, map<string, ll>> M;
unordered_map<int, map<string, ll>> F;
unordered_map<int, map<string, ll>> B;
unordered_map<string, int> db;

ll helper(string a, string b, unordered_map<int, map<string, ll>>& s) {
    auto itlow= s[b.length()].lower_bound(a);
    auto itup = s[b.length()].upper_bound(b);
    ll total = 0;
    while (itlow != itup) {
        total += itlow->second;
        itlow++;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    for (int i=1; i<30; i++) {
        M[i] = map<string, ll>();
        F[i] = map<string, ll>();
        B[i] = map<string, ll>();
    }
    while (true) {
        int c; cin >> c;
        string name; int gender; 
        if (c == 1) {
            cin >> name >> gender;
            db[name] = gender;
            for (int i=1; i <= name.length(); i++) {
                B[i][name.substr(0, i)]++;
                if (gender == 1) M[i][name.substr(0, i)]++;
                else F[i][name.substr(0, i)]++;
            }
        }
        if (c == 2) {
            cin >> name;
            gender = db[name];
            for (int i=1; i <= name.length(); i++) {
                B[i][name.substr(0, i)]--;
                if (gender == 1) M[i][name.substr(0, i)]--;
                else F[i][name.substr(0, i)]--;
            }
        }
        if (c == 3) {
            string start, end; 
            cin >> start >> end >> gender;
            if (gender == 0) cout << helper(start, end, B);
            else if (gender == 1) cout << helper(start, end, M);
            else cout << helper(start, end, F);
            cout << '\n';
        }
        if (c == 0) return 0;
    }

}