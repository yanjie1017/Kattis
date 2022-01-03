#include <iostream>
using namespace std;

int main(){
    int megabyte;
    int numOfLine;
    int usage;

    cin >> megabyte;
    cin >> numOfLine;

    int data = 0;

    for (int i=0; i<numOfLine; i++){
        data += megabyte;
        cin >> usage;
        data -= usage;
    }
    data += megabyte;
    cout << data;
}