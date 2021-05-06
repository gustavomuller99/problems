#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        c[i] -= k;
    }
    sort(c.begin(), c.end());
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        if (c[i] <= 0) continue;
        int l = -1, r = c.size();
        ll x = -c[i] + 1;
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(c[mid] >= x) r = mid;
            else l = mid;
        }
        ans += i - r;
    }
    cout << ans << endl;
}
