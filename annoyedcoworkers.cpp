#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

struct compareWorker {
    bool operator()(const pair<ll, ll> a, const pair<ll, ll> b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
struct compareOutput {
    bool operator()(const ll a, const ll b) {
        return a < b;
    }
};

int main() {   
    ll h, c; cin >> h >> c;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compareWorker> Q;
    priority_queue<ll, vector<ll>, compareOutput> Output;
    for (ll i=0; i<c; i++) {
        ll ini, incre; cin >> ini >> incre;
        Q.push({ini+incre, incre});
        Output.push(ini);
    }
    for (ll i=0; i<h; i++) {
        pair<ll, ll> temp = Q.top();
        Q.pop();
        Output.push(temp.first);
        temp.first += temp.second;
        Q.push(temp);
    }
    cout << Output.top();
}