#include <bits/stdc++.h>
using namespace std;
vector<double> a, p;
vector<pair<double, int>> m;
int n, d;
pair<bool, pair<int, int>> f(double x) {

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    d--;
    a.resize(n);
    p.resize(n);
    m.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double l = 0, r = 1;
    while(f(r).first) r *= 2;
    pair<int, int> ans;
    while(r > l + 1) {
        double mid = (r + l) / 2;
        auto rt = f(mid);
        if(rt.first) {
            l = mid;
            ans = rt.second;
        }
        else r = mid;
    }
    cout << ans.first << " " << ans.second << "\n";
}
