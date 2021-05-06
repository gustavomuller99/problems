#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(200003), dp(200003);
        vector<bool> b(200003);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x; a[x]++, b[x] = true;
        }
        for (int i = 1; i < a.size(); ++i) {
            if(!b[i]) continue;
            dp[i] = max(dp[i], a[i]);
            for (int j = 2*i; j < b.size(); j += i) {
                if(b[j]) dp[j] = max(dp[j], dp[i] + a[j]);
            }
        }
        int mx = 0;
        for (int i = 0; i < dp.size(); ++i) {
            mx = max(mx, dp[i]);
        }
        cout << n - mx << "\n";
    }
}
