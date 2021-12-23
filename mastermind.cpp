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

    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    int r = 0; int s = 0;
    unordered_map<char, int> A;
    unordered_map<char, int> B;
    unordered_set<char> record;
    for (int i=0; i<n; i++) {
        if (a[i] == b[i]) {
            r++; continue;
        }
        A[a[i]]++; B[b[i]]++;
        record.insert(a[i]); record.insert(b[i]);
    }

    auto it = record.begin();
    while (it != record.end()) {
        s += min(A[*it], B[*it]);
        it++;
    }
    cout << r << ' ' << s;

}