#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; ll k; cin>>n>>k;
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) cin>>h[i];
        int ans;
        while(1) {
            int i;
            for (i = 0; i < n-1; ++i) {
                if(h[i] >= h[i+1]) continue;
                h[i]++;
                k--;
                break;
            }
            if(i == n-1) { ans = -2; break; }
            if(k == 0) { ans = i; break; }
        }
        cout << ans+1 << "\n";
    }
}
