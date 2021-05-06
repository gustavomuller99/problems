#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,m; cin>>n>>m;
    vector<ll> a(n), b(m), ans;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int j = 0; j < m; ++j) cin>>b[j];
    int l = 0, r = 0;
    while(r < b.size()) {
        while(l < a.size() && a[l] < b[r]) l++;
        r++;
        ans.push_back(l);
    }
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
}
