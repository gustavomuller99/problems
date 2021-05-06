#include <bits/stdc++.h>
using namespace std;
double c;
bool f(double x) {
    return x*x + sqrt(x) >= c;
}
int main() {
    cin >> c;
    double l = 1, r = 1e10;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << setprecision(20) << l << "\n";
}
