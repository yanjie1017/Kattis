#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include<tuple>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef tuple<ll, ll, ll> e;

vector<vi> AL;
priority_queue<e, vector<e>, greater<e>> EL;
vector<ll> visited;
set<ll> infected;
queue<ll> q;
set<ll> room;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("contact.in","r",stdin);

    ll n, d; cin >> n >> d;
    ll c; cin >> c;
    AL.assign(n+1, vi());
    visited.assign(n+1, 0);

    while (c--) {
        ll i; cin >> i; 
        infected.insert(i); 
        q.emplace(i); visited[i] = 1; //??
    } 

    for (ll i=1; i<=n; i++) {
        ll a, b; cin >> a >> b;
        EL.emplace(make_tuple(a,0,i));
        EL.emplace(make_tuple(b,1,i));
    }

    while (!EL.empty()) {
        auto [_,c,i] = EL.top(); EL.pop();
        if (c == 0) {           //arrive
            auto t = room.begin();
            while (t != room.end()) {
                AL[*t].push_back(i);
                AL[i].push_back(*t);
                t++;
            }
            room.emplace(i);
        } else {                //leave
            room.erase(i);
        }
    }

    ll count = q.size(); 
    while (!q.empty()) {
        ll curr = q.front(); q.pop(); count--;
        for (auto& x:AL[curr]) {
            if (!visited[x]) {
                visited[x] = 1; q.emplace(x); infected.emplace(x);
            }
        }          
        if (count == 0) {
            d--; count = q.size();
        }
        if (d == 0) break;
    }
    
    auto pr = infected.begin();
    while (pr != infected.end()) {
        cout << *pr << " "; pr++;
    }   
}
