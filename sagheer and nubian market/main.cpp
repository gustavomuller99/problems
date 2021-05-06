#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int n; ll s;
vector<ll> b;
pair<bool, ll> f(int x) {
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = b[i] + (i+1)*x;
    }
    sort(p.begin(), p.end());
    ll sum = 0;
    for (int i = 0; i < x; ++i) {
        sum += p[i];
    }
    if(sum <= s) return {true, sum};
    else return {false, 0};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll ans = 0;
    int l = 0, r = n+1;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        auto rt = f(mid);
        if(rt.first) {
            l = mid;
            ans = rt.second;
        }
        else r = mid;
    }
    cout << l << " " << ans;
}
