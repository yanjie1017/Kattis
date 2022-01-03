#include <iostream>
#include <sstream> 
using namespace std;


string helper(int a, int b, int c)
{   
    if (a+b == c){
        return "Possible";
    } else if ((a-b == c) || (b-a == c)){
        return "Possible";
    } else if (a*b == c){
        return "Possible";
    } else if (((float)a / (float)b == (float)c) || ((float)b / (float)a == (float)c)) {
        return "Possible";
    } else {
        return "Impossible";
    }
}

int main()
{
    int numOfInput;
    char ws;
    string output = "";
    cin >> numOfInput;
    ws = cin.get();

    for (int i=0; i<numOfInput; i++){
        string input;
        getline(cin, input);

        stringstream ss;
        ss << input;

        string str_a, str_b, str_c;
        int a, b, c;
        ss >> str_a;
        ss >> str_b;
        ss >> str_c;
        a = stoi(str_a);
        b = stoi(str_b);
        c = stoi(str_c);

        output += helper(a, b, c);
        output += "\n";
    }
    cout << output;
    return 0;
}