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
    vector<int> v; v.assign(n, 0);
    int arrow = 0;

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    while (!v.empty()) {
        arrow++;
        int total = 0; 
        int index; 
        vector<int> clear;
        for (int i=0; i<n; i++) {
            int curr = 1; int step = 1;
            vector<int> temp; temp.push_back(i);
            while (i+step < v.size()) {
                if (v[i] - step == 0) break;
                if (v[i+step] == v[i] - step) {
                    curr++;
                    temp.push_back(i+step);
                }
                step++;
            }
            if (curr > total) {
                total = curr; index = i; clear = temp;
            }
        }
        for (int i=clear.size()-1; i>=0; i--) {
            v.erase(v.begin()+clear[i]);
        }
    }
    cout << arrow;
}