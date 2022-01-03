#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
    int e, f, c;
    cin >> e >> f >> c;
    int total = e+f;
    int count = 0;
    while (total >= c){
        int drink = total/c;
        count += drink;
        total -= drink*c;
        total += drink;
    }
    cout << count;
    return 0;
}