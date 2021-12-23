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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    ll machines, items, maxtime, totaltime, temp, input;
    cin >> machines >> items; 
    maxtime = 0; totaltime = 0; 
    for (ll i=1; i<=machines; i++) {
        cin >> temp;
        maxtime = max(temp, maxtime);
        totaltime += temp;
    }
    for (ll i=2; i<=machines; i++) {
        cin >> input;
    }
    cout << (maxtime*items + totaltime - maxtime);
}