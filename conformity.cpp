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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("con.in","r",stdin);

    int n; cin >> n;
    unordered_map<string, int> m;
    multiset<int, greater<int>> count;
    for (int i=0; i<n; i++) {
        string out; 
        priority_queue<int> temp;
        for (int i=0; i<5; i++) {
            int num; cin >> num;
            temp.emplace(num);
        }
        while (!temp.empty()) {
            out += to_string(temp.top()); temp.pop();
        }
        m[out] += 1;
    }
    auto it = m.begin();
    while (it != m.end()) {
        count.emplace((*it).second);
        it++;
    }
    int ans = 0;
    int max = *count.begin();  
    int second = *(++count.begin());
    if (max > second) {
        cout << max; return 0;
    }
    auto bound = count.upper_bound(max);
    auto start = count.begin(); 
    while (start != bound) {
        ans += *start; start++;
    }
    cout << ans;
}