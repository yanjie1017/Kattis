#include <iostream>
#include <iomanip>
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

ll min_per_week = 24*60*7;
ll min_per_day = 24*60;

unordered_map<int, string> m = {
    {0,"Saturday"},
    {1, "Sunday"},
    {2, "Monday"},
    {3, "Tuesday"},
    {4, "Wednesday"},
    {5, "Thursday"},
    {6, "Friday"}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    string a, b, ad, bd; cin >> a >> b >> ad >> bd;
    
    ll at = stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
    ll bt = stoi(b.substr(0,2))*60 + stoi(b.substr(3,2));
    ll adt = stoi(ad.substr(0,2))*60 + stoi(ad.substr(3,2));
    ll bdt = stoi(bd.substr(0,2))*60 + stoi(bd.substr(3, 2));
    ll atnow = at; ll btnow = bt;
    bool arepeat = false; bool brepeat = false;

    while (atnow != btnow) {
        if (atnow != at && atnow % min_per_week == at) arepeat = true;
        if (btnow != bt && btnow % min_per_week == bt) brepeat = true;
        if (arepeat && brepeat) {
            cout << "Never"; return 0;
        }
        if (atnow < btnow) atnow += adt;
        else btnow += bdt;
    }
    int day = atnow % min_per_week / min_per_day;
    int hr = atnow % min_per_day / 60;
    int min = atnow % min_per_day % 60;
    cout << m[day] << '\n';
    cout << setfill('0') << setw(2) << to_string(hr);
    cout << ':';
    cout << setfill('0') << setw(2) << to_string(min);
}
