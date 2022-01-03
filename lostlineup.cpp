#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int num_of_ppl;
    char ws;
    string output =  "";

    cin >> num_of_ppl;
    ws = cin.get();
    int list[num_of_ppl];
    list[0] = 1;

    string input;
    getline(cin, input); 

    stringstream ss;
    ss << input;

    for (int i=0; i<num_of_ppl-1; i++){
        string str_n;
        ss >> str_n;
        int n = stoi(str_n);
        int ppl = i+2;
        int pos = 1+n;
        list[pos] = ppl;
    }
    for (int i=0; i<num_of_ppl; i++){
        output += to_string(list[i]);
        output += " ";
    }
    cout << output;
    return 0;
}