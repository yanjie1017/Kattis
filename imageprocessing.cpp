#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int h, w, n ,m; cin >> h >> w >> n >> m;
    vector<vector<int>> matrix; matrix.assign(h, vector<int>(w,0));
    vector<vector<int>> kernel; kernel.assign(n, vector<int>(m,0));
    vector<vector<int>> image; image.assign(h-n+1, vector<int>(w-m+1,0));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            cin >> kernel[i][j];
        }
    }
    
    for (int i=0; i<h-n+1; i++) {
        for (int j=0; j<w-m+1; j++) {
            int total = 0;
            for (int k=0; k<n; k++) {
                for (int l=0; l<m; l++) {
                    total += kernel[k][l] * matrix[i+k][j+l];
                }
            }
            image[i][j] = total;
        }
    }
    for (int i=0; i<h-n+1; i++) {
        for (int j=0; j<w-m+1; j++) {
            cout << image[i][j] << ' ';
        }
        cout << '\n';
    }
}