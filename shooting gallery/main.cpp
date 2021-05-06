#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n; cin>>n;
    vector<pair<pair<ll, double>, pair<ll,ll>>> a(n);
    vector<double> d(n);
    for (int i = 0; i < n; ++i) cin>>a[i].second.first>>a[i].second.second>>a[i].first.first>>a[i].first.second;
    sort(a.begin(), a.end());
    d[0] = a[0].first.second;
    for (int i = 1; i < n; ++i) {
        d[i] = a[i].first.second;
        ll t = a[i].first.first, x = a[i].second.first, y = a[i].second.second;
        for (int j = 0; j < i; ++j) {
            ll t1 = a[j].first.first, x1 = a[j].second.first, y1 = a[j].second.second;
            if(sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)) - double (t - t1) < 10e-6) d[i] = max(d[i], d[j] + a[i].first.second);
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, d[i]);
    cout << setprecision(20) << ans;
}
