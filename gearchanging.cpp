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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m;
    double p;
    cin >> n >> m >> p;
    p /= 100;

    vector<double> crank(n);
    for(int i; i<n; i++) {
        cin >> crank[i];
    }

    vector<double> back(m);
    for(int i; i<m; i++) {
        cin >> back[i];
    }

    set<double> q;
    for(auto& i : crank) {
        for(auto& j : back) {
            q.insert(i/j);
        }
    }

    double curr = *q.begin(); 
    auto it = q.begin(); 
    while (it != q.end()) {
        it++;
        if(curr + curr*p < *it) {
            cout << "Time to change gears!" << endl;
            return 0;
        }
        curr = *it;
    }
    cout << "Ride on!" << endl;
}