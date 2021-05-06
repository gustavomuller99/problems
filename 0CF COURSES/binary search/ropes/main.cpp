#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, k;

bool f(double x) {
    long long s = 0;
    for (int i = 0; i < a.size(); ++i) {
        s += (long long) floor(a[i] / x);
    }
    return s >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    double l = 0, r = 1;
    while(f(r)) r *= 2;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(20) << l << "\n";
}
