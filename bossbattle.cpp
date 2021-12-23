#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    if (num <= 3){
        cout << 1;
    } else {
        cout << (num-2);
    }
}