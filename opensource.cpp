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

bool cmp (pair<int,string> a, pair<int,string> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    string x, project;
    unordered_map<string, unordered_set<string>> P;
    unordered_map<string, int> N;
    while (getline(cin,x)) {
        if (x == "0") return 0;
        if (x == "1") {
            priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(&cmp)> Q(cmp);
            for (auto& S:P) {
                int c = 0;
                for (auto& s:S.second) {
                    if (N[s] > 1) continue;
                    if (N[s] <= 0) continue;
                    c++;
                }
                Q.emplace(c, S.first); 
            }
            while (!Q.empty()) {
                cout << Q.top().second << " " << Q.top().first << endl; Q.pop();
            }
            P.clear();
            N.clear();
            continue;
        }
        if (x[0] < 'a') {   //project name
            project = x;
            P[project] = unordered_set<string>();
            continue;
        }
        if (P[project].find(x) == P[project].end()) {
            N[x]++;
            P[project].insert(x);
        }
    }

}