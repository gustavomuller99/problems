#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,ans=0; cin>>n>>k;
    vector<int> a(n), t(n), p1(n+1), p2(n+1);
    for (int i = 0; i < n; ++i) cin>>a[i], p2[i+1] = a[i] + p2[i];
    for (int i = 0; i < n; ++i) cin>>t[i];
    for (int i = 0; i < n; ++i) p1[i+1] = (t[i] == 1 ? a[i] : 0) + p1[i];
    for (int i = k-1; i < n; ++i) {
        int r = i+1, l = i+1-k;
        ans = max(ans, p2[r] - p2[l] + p1[l] - p1[0] + p1[n] - p1[r]);
    }
    cout << ans;
}
