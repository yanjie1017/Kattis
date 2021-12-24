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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; cin >> n; 
    while (n--) {
        cin.get();
        string record; getline(cin, record);
        string animal, action, sound; 
        unordered_set<string> M;
        while (cin >> animal) {
            cin >> action >> sound;
            if (action == "does") {
                cin >> sound >> sound;
                break;
            }
            M.insert(sound);
        }
        stringstream s(record);
        string word;
        while (s >> word) {
            if (M.find(word) == M.end()) cout << word << ' ';
        }
        cout << endl;
    }
}