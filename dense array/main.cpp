#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, ans = 0; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n-1; ++i) {
            int x = min(a[i], a[i+1]), y = max(a[i], a[i+1]);
            while(y / x + (y % x != 0) > 2) x *= 2, ans++;
        }
        cout << ans << "\n";
    }
}
