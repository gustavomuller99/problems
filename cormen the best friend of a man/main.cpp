#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += max(0, k - (d[i] + d[i-1]));
        d[i] += max(0, k - (d[i] + d[i-1]));
    }
    cout << ans << "\n";
    for(int x : d) {
        cout << x << " ";
    } cout << "\n";
}
