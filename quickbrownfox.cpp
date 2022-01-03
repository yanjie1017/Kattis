#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    char ws = cin.get();
    string output = ""; 
    string lib = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<n; i++){
        bool flag = true;
        string input;
        string tempOutput = "";
        getline(cin, input);

        std::for_each(input.begin(), input.end(), [](char & c) {
            c = ::tolower(c);
        });

        for (int j=0; j<26; j++){
            if (input.find(lib[j]) == std::string::npos){
                tempOutput += lib[j];
                flag = false;
            }
        }
        if (flag) {
            output += "pangram";
        } else {
            output += "missing ";
            output += tempOutput;
        }
        output += "\n";
    }
    cout << output;
}