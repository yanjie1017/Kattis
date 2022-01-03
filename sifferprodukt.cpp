#include <iostream>
using namespace std;

int helper(int x){
    int count = 0;
    int dividend = 10;
    int digit[4] = {0,0,0,0};
    int output = 0;

    while (x != 0){
        digit[count] = x%10;
        x /= dividend;
        count += 1;
    }   
   
    for (int i=0; i<4; i++){
        if (digit[i] != 0 && output == 0){
            output = digit[i];
        } else if (digit[i] != 0){
            output *= digit[i];
        }
    }
    return output;
}

int main(){
    int input;
    cin >> input;

    while (input > 9){
        input = helper(input);
    }
    cout << input;
    return 0;
}