#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
struct id {
    string name;
    ll arrivalTime;
    ll severity;
    ll priority;
};

auto cmp = [](id a, id b) {
    if (a.priority != b.priority) 
        return a.priority < b.priority;
    return a.name > b.name;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; ll T; cin >> N >> K; 
    set<id, decltype(cmp)> S(cmp);
    set<string> Name;
    for (int i=0; i<N; i++) {
        int Q; cin >> Q;
        if (Q == 1) {
            id newId;
            cin >> newId.arrivalTime >> newId.name >> newId.severity;
            newId.priority = newId.severity - K*(newId.arrivalTime);
            Name.insert(newId.name);  //O(logN)
            S.insert(newId);  //O(logN)
        } else if (Q == 2) {
            cin >> T; 
            if (S.empty()) {
                cout << "doctor takes a break\n";
                continue;
            }
            while (true) {
                if (S.empty()) {
                    cout << "doctor takes a break\n";
                    break;
                }
                auto it = S.end();
                string currName = (*(--it)).name;
                auto lo = Name.find(currName);  //O(logN)
                S.erase(it);  //O(1)
                if (lo != Name.end())  {
                    cout << currName << '\n';
                    Name.erase(lo);  //O(1)
                    break;
                }
            }
        } else {
            string rmName;
            cin >> T >> rmName;
            auto lo = Name.find(rmName);  //O(logN)
            if (lo != Name.end()) 
                Name.erase(lo);  //O(1)
        }
    }
    return 0;
}