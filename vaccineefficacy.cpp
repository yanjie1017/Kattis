#include <iostream>
#include <iomanip>  
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct vaccine {
    int total = 0;
    int v1 = 0;
    int v2 = 0;
    int v3 = 0;
};

int main() {
    //freopen("vaccine.in","r",stdin);
    int n; cin >> n;
    vaccine N;
    vaccine Y;
    while (n--) {
        string m; cin >> m;
        switch (m[0])
        {
        case 'Y':
            Y.total += 1;
            if (m[1] == 'Y') Y.v1 += 1;
            if (m[2] == 'Y') Y.v2 += 1;
            if (m[3] == 'Y') Y.v3 += 1;
            break;
        case 'N':
            N.total += 1;
            if (m[1] == 'Y') N.v1 += 1;
            if (m[2] == 'Y') N.v2 += 1;
            if (m[3] == 'Y') N.v3 += 1;
            break;
        }
    }

    double v1 = (double)Y.v1/Y.total; double c1 = (double)N.v1/N.total;
    double v2 = (double)Y.v2/Y.total; double c2 = (double)N.v2/N.total;
    double v3 = (double)Y.v3/Y.total; double c3 = (double)N.v3/N.total;
    double e1 = 1 - v1/c1; double e2 = 1 - v2/c2; double e3 = 1 - v3/c3;
    cout << fixed;
    cout << setprecision(6);
    if (e1 <= 0) cout << "Not effective\n";
    else cout << e1*100 << '\n';
    if (e2 <= 0) cout << "Not effective\n";
    else cout << e2*100 << '\n';
    if (e3 <= 0) cout << "Not effective\n";
    else cout << e3*100 << '\n';

}