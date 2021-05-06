#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n; double k;
bool f(double x) {
    double rm = 0, rc = 0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] > x) rm += a[i] - x;
        else rc += x - a[i];
    }
    return rm - (rm*k)/100 > rc;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    double l = INT_MAX, r = INT_MIN;
    for (int i = 0; i < n; ++i) cin >> a[i], l = min(l, (double) a[i]), r = max(r, (double) a[i]);
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(20) << l << "\n";
}
