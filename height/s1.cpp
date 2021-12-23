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
    
    while (n--) {
        int counter = 0; int c;
        cin >> c;

        vector<int> v(20,0);
        for (int i=0; i<20; i++) {
            cin >> v[i];
        }

        for (int i=1; i<20; i++) {
            int temp = v[i];
            int j = i-1;
            while (temp<v[j] && j>=0) {
                v[j+1] = v[j];
                j--;
                counter++;
            }
            v[j+1] = temp;
        }
        cout << c << ' ' << counter << endl;
    }
}
