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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m; cin >> n >> m;
    vector<int> l;
    for (int i=1; i<=n; i++) {
       l.push_back(i);
    }
    while (m--) {
        string a, b; cin >> a >> b;
        int win = stoi(a.substr(1, a.length()-1)); 
        int lose = stoi(b.substr(1, b.length()-1));

        for (int i=0; i<l.size(); i++) {
            if (l[i] == win) break;
            if (l[i] == lose) {
                int swap_index;
                for (int j=i+1; j<l.size(); j++) 
                    if (l[j] == win) 
                        swap_index = j+1;
                l.insert(l.begin()+swap_index, lose);
                l.erase(l.begin()+i);
                break;
            }
        }
    }
    for (auto& x:l) {
        cout << 'T' << x << ' ';
    }
}