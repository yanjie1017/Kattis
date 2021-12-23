#include <iostream>
using namespace std;

int main(){
    int num;
    int L = 0;
    int R = 0;
    int T = 0;
    int B = 0;
    int minNum;
    char ws;

    cin >> num;
    ws = cin.get();

    for (int i=0; i<num; i++){
        string sword; //tblr
        cin >> sword;
        ws = cin.get();
        if (sword[0] == '0') { T += 1; }
        if (sword[1] == '0') { B += 1; }
        if (sword[2] == '0') { L += 1; }
        if (sword[3] == '0') { R += 1; }
    }
    minNum = (min(T+B, L+R))/2 ;
    cout << minNum << " " << (T+B-minNum*2) << " " << (L+R-minNum*2);
    return 0;
}