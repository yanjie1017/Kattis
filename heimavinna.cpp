#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string input, data;
    int total = 0;
    getline(cin, input);
    stringstream X(input);
    while (getline(X, data, ';')){
        std::size_t found = data.find('-');
        if (found != std::string::npos) {
            total += ( stoi(data.substr(found+1))-stoi(data.substr(0,found))+1 );
        } else {
            total += 1;
        }
    }
    cout << total;
    return 0;
}