#include <iostream>
#include <sstream> 
using namespace std;

int main()
{
    string input;
    string output = "";
    getline(cin, input);

    stringstream ss;
    ss << input;

    string str_a, str_b, str_n;
    int a, b, n;
    ss >> str_a;
    ss >> str_b;
    ss >> str_n;
    a = stoi(str_a);
    b = stoi(str_b);
    n = stoi(str_n);

    for (int i=1; i<=n; i++){
        string out = "";
        if (i%a == 0) { out += "Fizz"; }
        if (i%b == 0) { out += "Buzz"; } 
        if (out == "") { out = to_string(i); }
        output += (out + "\n");
    }
    cout << output;
    return 0;
}
