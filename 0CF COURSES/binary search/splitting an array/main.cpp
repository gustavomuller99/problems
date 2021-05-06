#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
int k;
bool f(ll x) {
    int v = 1;
    if(a[0] > x) return false;
    ll c_s = a[0];
    for(int i = 1; i < a.size(); i++) {
        c_s += a[i];
        if(c_s > x) {
            c_s = a[i];
            v++;
        }
        if(a[i] > x) return false;
    }
    return v <= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 0, r = 1;
    while(!f(r)) r *= 2;
    while(r > l + 1) {
        ll mid = (r + l) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}
