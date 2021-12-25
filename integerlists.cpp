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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n;
    while (n--) {
        string ins; cin >> ins;
        int m; cin >> m;
        deque<int> q;

        char x; cin >> x;
        if (m == 0) cin >> x;
        while (m--) {
            int num; cin >> num; cin >> x;
            q.push_back(num);
        }

        bool isReverse = false; bool isError = false;
        for (const auto& s:ins) {
            if (s == 'R') {
                isReverse = !isReverse;
                continue;
            }
            if (s == 'D') {
                if (q.empty()) {
                    cout << "error\n";
                    isError = true;
                    break;
                }
                if (isReverse) q.pop_back();
                else q.pop_front();
            }
        }

        if (isError) continue;

        cout << '[';
        while(!q.empty()) {
            if(isReverse) {
                cout << q.back();
                q.pop_back();
            }
            else {
                cout << q.front();
                q.pop_front();
            }
            if(q.size() != 0) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}