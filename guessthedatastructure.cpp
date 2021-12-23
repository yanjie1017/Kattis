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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int n; 
    while (cin >> n) {
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        bool isq = true;
        bool iss = true;
        bool ispq = true;

        int counter = 0;

        while (n--) {
            int instruction, x;
            cin >> instruction >> x;

            if (instruction == 1) {
                q.push(x);
                s.push(x);
                pq.push(x);
                counter++;
            } else {
                if (counter <= 0) {
                    isq = false;
                    ispq = false;
                    iss = false;
                    while (n--) {
                        cin >> instruction >> x;
                    }
                    break;
                }
                if (x != q.front()) {
                    isq = false;
                }
                if (x != s.top()) {
                    iss = false;
                }
                if (x != pq.top()) {
                    ispq = false;
                }
                q.pop();
                s.pop();
                pq.pop();
                counter--;
            }
        }

        int num = 0;
        if (isq) num++;
        if (ispq) num++;
        if (iss) num++;

        if (num == 0) cout << "impossible\n";
        if (num == 1) {
            if (isq) cout << "queue\n";
            if (ispq) cout << "priority queue\n";
            if (iss) cout << "stack\n";
        }
        if (num > 1) cout << "not sure\n";
    }
}