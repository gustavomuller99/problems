#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n), d(n);
        bool e = false;
        for (int i = 0; i < n; ++i) { cin >> a[i]; a[i]--; }
        int l = 0, r = 0;
        while(l != n) {
            int c = a[l];
            while(a[r] == c && r != n) r++;
            if(l == 0 && r-1 == n-1) {d[c] = 0; e = true; break;}
            if(d[c] == 0) {
                if(l == 0 || r-1 == n-1) d[c] = 1;
                else d[c] = 2;
            } else {
                if(l != 0 && r-1 != n-1) d[c]++;
            }
            l = r;
        }
        if(e || n==1) cout << 0 << "\n";
        else {
            int ans = INT_MAX;
            for (int i = 0; i < n; ++i) if(d[i]) ans = min(ans, d[i]);
            cout << ans << "\n";
        }
    }
}
