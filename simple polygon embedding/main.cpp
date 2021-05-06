#include <bits/stdc++.h>
#define PI 3.14159265358979323846
using namespace std;

int main() {

    int t;
    cin >> t;
    int n;

    cout << fixed;
    cout << setprecision(9);
    while(t--) {
        cin >> n;
        n = 2*n;

        double a = (n-2)* PI / n;
        a /= 2;
        double ans = tan(a);
        cout << ans << endl;

    }

}
