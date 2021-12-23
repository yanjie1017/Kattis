#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
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

unordered_map<char, char> M = {
    {'}','{'},
    {']','['},
    {')','('},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    string input;
    getline(cin, input);

    deque<char> S; 
    for (int i=0; i<input.length(); i++) {
        char x = input[i];
        if (x == '<') S.pop_back();
        else S.push_back(x);
    }
    for (auto x:S) {
        cout << x;
    }
}
