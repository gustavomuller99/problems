#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, ans = 0; cin>>n;
    vector<int> a(n), d(1e6+1);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        d[a[i]]++;
        for (int j = 2*a[i]; j < 1e6+1; j+=a[i]) {
            d[j] = max(d[j], d[a[i]]);
        }
        ans = max(ans, d[a[i]]);
    }
    cout << ans;
}
