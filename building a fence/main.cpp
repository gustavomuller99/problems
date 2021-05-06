#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,k; cin>>n>>k;
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) cin>>h[i];
        int l = 0, r = 0; bool ans = true, u = true;
        while(l != n-1) {
            if(u) {
                u = false;
                while(r != n-1 && h[r+1] >= h[r]) r++;
                ll hgt;
                if(l != 0) hgt = h[l] + k - 1;
                else hgt = h[l];
                for (int i = l; i < r; ++i) {
                    hgt = min(hgt + k - 1, h[i+1] + k - 1);
                    if(hgt < h[i+1]) ans = false;
                }
                l = r;
            } else {
                u = true;
                while(r != n-1 && h[r+1] <= h[r]) r++;
                ll hgt = h[l];
                for (int i = l; i < r; ++i) {
                    hgt = hgt - (k-1);
                    hgt = max(hgt, h[i+1]);
                    if(hgt - h[i+1] > k - 1) ans = false;
                }
                if(r == n-1 && hgt != h[n-1]) ans = false;
                l = r;
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
