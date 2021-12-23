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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n, m; cin >> n >> m;
    vector<int> nowtime; nowtime.assign(m,0);
    vector<int> answer;

    for (int i=0; i<n; i++) {
        int x; cin >> x;
        int total = nowtime[0] + x; nowtime[0] = total;
        for (int j=1; j<m; j++) {
            cin >> x;
            total = max(total+x, nowtime[j]+x);
            nowtime[j] = total;
        }
        answer.push_back(total);
    }

    for (auto& x:answer) {
        cout << x << ' ';
    }

}