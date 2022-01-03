#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strList;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        strList.push_back(input);
    }
    if (n == 1) {
        cout << strList[0];
        return 0;
    }
    
    vector<list<int>> vec;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        int afound = -1, bfound = -1;
        int idx = 0;
        for (auto& elem:vec) {
            if (elem.front() == a) 
                afound = idx; 
            if (elem.front() == b)
                bfound = idx;
            idx++;
        }
        if (afound == -1 && bfound == -1) {
            list<int> temp;
            temp.push_back(a); 
            temp.push_back(b);
            vec.push_back(temp);
        } else if (bfound == -1) {
            vec[afound].push_back(b);
        } else if (afound == -1) {
            vec[bfound].push_front(a);
        } else {
            vec[afound].splice(vec[afound].end(), vec[bfound]);
            vec.erase(vec.begin() + bfound);
        }
    }
    for (auto& index:vec[0]) {
        cout << strList[index-1];
    }
    return 0;
}