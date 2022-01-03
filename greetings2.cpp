#include <iostream>
using namespace std;

int main()
{
  string input;
  string output = "";

  cin >> input;
  char head = input[0];
  char tail = input.back();
  string middle = input.substr(1, input.length()-2);

  if (head == 'h' && tail == 'y'){
      int len = middle.length();
      string mid(len*2, 'e');
      output = head + mid + tail;
  }

  cout << output;
  return 0;
}