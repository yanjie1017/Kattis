#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int Func1(vector<int32_t>);
int Func2(vector<int32_t>, int);
int Func3(vector<int32_t>, int);
void Func4(vector<int32_t>, int);
void Func5(vector<int32_t>, int);

int main(){
    int n, t;
    cin >> n;
    cin >> t;

    vector<int32_t> A;
    for (int i=0; i<n; i++){
        int32_t temp;
        cin >> temp;
        A.push_back(temp); 
    }
    switch(t){
        case 1:
            Func1(A);
            break;    
        case 2:
            Func2(A, n);
            break; 
        case 3:
            Func3(A, n);
            break;
        case 4:
            Func4(A, n);
            break;    
        case 5:
            Func5(A, n);
            break;      
    }
    return 0;
}

int Func1(vector<int32_t> A){
    for (const auto& x: A){
        if (x<=7777){
            int32_t substract = 7777-x;
            if (std::find(A.begin(), A.end(), substract) != A.end()){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}

int Func2(vector<int32_t> A, int size){
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            if (A[i] == A[j]){
                cout << "Contains duplicate";
                return 0;
            }
        }
    }
    cout << "Unique";
    return 0;
}

int Func3(vector<int32_t> A, int size){
    std::sort(A.begin(), A.end());
    bool duplicate = false;
    int32_t prev = -1;
    int count = 1;
    for (const auto& x: A){
        if (x == prev){
            count++;
            duplicate = true;
        } else {
            duplicate = false;
            count = 1;
        }
        if (count > size/2){
            cout << x;
            return 0;
        }
        prev = x;
    }
    cout << -1;
    return 0;
}

void Func4(vector<int32_t> A, int size){
    std::sort(A.begin(), A.end());
    if (size%2 == 0){
        cout << A[size/2-1] << " " << A[size/2];
    } else {
        cout << A[size/2];
    }
}

void Func5(vector<int32_t> A, int size){
    std::sort(A.begin(), A.end());
    for (const auto& x: A){
        if (x>=100 && x<=999)
            cout << x << " ";
    }
}