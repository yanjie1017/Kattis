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
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

vi v;
vector<vi> AL;
vector<ll> step;
vector<ll> startPoints;
ll maxValue;

int left(ll i) {
    ll value = v[i];
    ll pos = i;
    while (pos >= 0) {
        if (v[pos] <= value) pos--;
        else {
            return pos;
        }
    }
    return i;
}

int right(ll i) {
    ll value = v[i];
    ll pos = i;
    while (pos<v.size()) {
        if (v[pos] <= value) pos++;
        else {
            return pos;
        }
    }
    return i;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in","r",stdin);
    
    ll n; cin >> n;
    v.assign(n,0); step.assign(n, INT_MAX); AL.assign(n, vi()); 

    maxValue = 0;
    for (ll i=0; i<n; i++) {
        cin >> v[i];
        maxValue = max(maxValue, v[i]);
    }
    for (ll i=0; i<n; i++) {
        int l = left(i); AL[l].push_back(i);
        int r = right(i); AL[r].push_back(i);
        if (v[i] == maxValue) startPoints.push_back(i);
    }
    
    queue<ll> q;
    for (auto& i:startPoints) {
        q.push(i);
        step[i] = 0;
    }
      
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int currStep = step[u] + 1;
        for (auto& v:AL[u]) {
            if (step[v] > currStep) {
                step[v] = currStep;
                q.push(v);
            }
        }
    }

    for (auto& x:step) {
        cout << x << " ";
    }
    
}
