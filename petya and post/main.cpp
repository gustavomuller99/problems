#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n; cin>>n;
    vector<ll> a(n),b(n);
    set<int> ans;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) cin>>b[i];
    ll p=a[0]-b[0], mn=a[0]-b[0];
    for (int i = 1; i < n; ++i) {
        p += (a[i]-b[i]);
        mn = min(mn, p);
    }
    for (int i = 0; i < n; ++i) {
        if(mn >= 0) ans.insert(i+1);
        mn -= (a[i]-b[i]);
    }
    p = a[n-1]-b[n-2], mn = a[n-1]-b[n-2];
    for (int i = n-2; i >= 0; --i) {
        p += (a[i]-b[(i ? i-1 : n-1)]);
        mn = min(mn, p);
    }
    for (int i = n-1; i >= 0; --i) {
        if(mn >= 0) ans.insert(i+1);
        mn -= (a[i]-b[(i ? i-1 : n-1)]);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}
