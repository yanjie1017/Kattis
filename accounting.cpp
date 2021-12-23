#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
    //freopen("1.in","r",stdin);
    int N, Q; cin >> N >> Q;
    unordered_map<int, int> M; //value
    unordered_map<int, int> T; //time
    ii value(0,0);
    for (int i=1; i<=Q; i++) {
        string event; cin >> event;
        if (event == "SET") {
            int j, x; cin >> j >> x;
            M[j] = x;  //1
            T[j] = i;  //1
        }
        if (event == "RESTART") {
            cin >> value.second;
            value.first = i;
        }
        if (event == "PRINT") {
            int j; cin >> j;
            auto it = M.find(j); //1
            if (it != M.end()) {
                if (T[j] > value.first)
                    cout << M[j] << '\n';  
                else
                    cout << value.second << '\n';
            }
            else
                cout << value.second << '\n';
        }        
    }
}
