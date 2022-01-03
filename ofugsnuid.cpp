#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int list[n];
    for (int i=0; i<n; i++){
        int input;
        cin >> input;
        list[i]=input;
    }
    for (int i=n-1; i>=0; i--){
        cout << list[i] << "\n";
    } 
}