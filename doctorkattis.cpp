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


priority_queue<tuple<int,int,string>> pq;
unordered_map<string, ii> db;
unordered_map<string, int> update;
unordered_map<string, int> del;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("doctor.in","r",stdin);
    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        if (a == 0) { //add
            string name; int p; cin >> name >> p;
            db[name] = ii(p,n);
            tuple<int,int,string> id = make_tuple(p,n,name);
            pq.emplace(id);
        } else if (a == 1) { //update
            string name; int p; cin >> name >> p;
            db[name].first += p;
            tuple<int,int,string> id = make_tuple(db[name].first,db[name].second,name);
            pq.emplace(id);
            update[name] = 1;
        } else if (a == 2) { //del
            string name; cin >> name;
            del[name] = 1;
        } else { //query
            string output = "The clinic is empty";
            while (!pq.empty()) {
                tuple<int,int,string> curr = pq.top(); 
                string name = get<2>(curr);
                if (del[name]) {
                    pq.pop(); continue;
                }
                if (update[name]) {
                    if (update[name] == 1) {
                        output = name; break;
                        update[name] += 1;
                    }
                    else {
                        pq.pop(); update[name] = 0;
                        continue;
                    }
                }
                output = name;
                break;
            }
            cout << output << '\n';
        }
    }
}