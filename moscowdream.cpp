#include <iostream>
#include <sstream> 
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    stringstream ss;
    ss << input;

    string str_a, str_b, str_c, str_n;
    int a, b, c, n;
    ss >> str_a;
    ss >> str_b;
    ss >> str_c;
    ss >> str_n;
    a = stoi(str_a);
    b = stoi(str_b);
    c = stoi(str_c);
    n = stoi(str_n);

    if (n >= 3){
        if (a > 0 && b > 0 && c > 0){
            int total = a + b + c;
            if (total - n >= 0){
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }


    return 0;
}