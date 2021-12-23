#include <iostream> 
#include <numeric>
#include <algorithm>
using namespace std;

void Func2(int32_t, int32_t);
void Func3(int32_t, int32_t, int32_t);
void Func4(int32_t[], int);
void Func5(int32_t[], int);
void Func6(int32_t[], int);
int Func7(int32_t[], int);

int main(){
    int n, t;
    cin >> n;
    cin >> t;

    int32_t A[n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    switch(t){
        case 1:
            cout << "7";
            break;
        case 2:
            Func2(A[0],A[1]);
            break;
        case 3:
            Func3(A[0],A[1],A[2]);
            break;
        case 4:
            Func4(A, n);
            break;
        case 5:
            Func5(A, n);
            break;
        case 6:
            Func6(A, n);
            break;
        case 7:
            Func7(A, n);
            break;        
    }
    return 0;
}

// Bigger, Equal or Smaller
void Func2(int32_t a, int32_t b){
    if (a > b){
        cout << "Bigger";
    } else if (a == b){
        cout << "Equal";
    } else {
        cout << "Smaller";
    }
}

// Print the median of three integers 
void Func3(int32_t a, int32_t b, int32_t c){
    int32_t list[3] = {a, b, c};
    bool swapped;
    do {
        swapped = false;
        for (int i=0; i<2; i++){
            if (list[i] > list[i+1]){
                int32_t temp = list[i+1];
                list[i+1] = list[i];
                list[i] = temp;
                swapped = true;
            }
        }
    } while (swapped);
    cout << list[1];
}

//  Print the sum of all integers
void Func4(int32_t a[], int size){
    int64_t sum = 0;
    for (int i=0; i<size; i++){
        sum += a[i];
    }
    cout << sum;
}

//  Print the sum of all even integers
void Func5(int32_t a[], int size){
    int64_t sum = 0;
    for (int i=0; i<size; i++){
        if (a[i] % 2 == 0){
            sum += a[i];
        }
    }
    cout << sum;
}

// Print the sequence of characters as a string
void Func6(int32_t a[], int size){
    string charLib = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<size; i++){
        cout << charLib[(a[i]%26)];
    }
}

int Func7(int32_t a[], int size){
    int index = 0;
    do{
        if (index == size-1){
            cout << "Done";
            return 0;
        }
        int temp = a[index];
        a[index] = -1;
        index = temp;     
    } while (index >= 0 && index < size);
    if (index == -1){
        cout << "Cyclic";
        return 0;
    }
    cout << "Out";
    return 0;
}