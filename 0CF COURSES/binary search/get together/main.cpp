#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, ll>> a;
bool f(double t) {
    pair<double, double> interval = {LLONG_MIN, LLONG_MAX};
    for(auto p : a) {
        interval = {max(interval.first, p.first - t*p.second), min(interval.second, p.first + t*p.second)};
    }
    return interval.first < interval.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    double l = -1, r = 1;
    while(!f(r)) r *= 2;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << setprecision(20) << r << "\n";
}
