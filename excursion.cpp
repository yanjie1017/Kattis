#include <iostream> 
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
    //input
    string in; cin >> in;
    string remaining = "";

    ll total = 0;
    int lastIndex = 0;

    for (int i=0; i<in.length(); i++) {
        if (in[i] == '0') {
            total += (i-lastIndex);
            lastIndex++;
        } else {
            remaining += in[i];
        }
    }
    
    int firstIndex = remaining.length()-1;
    for (int i=remaining.length()-1; i>=0; i--) {
        if (remaining[i] == '2') {
            total += (firstIndex-i);
            firstIndex--;
        }
    }
    cout << total;
    return 0;
}