#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m; cin>>n>>m;
    vector<ll> a(n), b(m), c;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int j = 0; j < m; ++j) cin>>b[j];
    int l = 0, r = 0;
    while(l < a.size() || r < b.size()) {
        if(l == a.size() || (r != b.size() && b[r] <= a[l])) {
            c.push_back(b[r]), r++;
        } else c.push_back(a[l]), l++;
    }
    for(ll x : c) cout << x << " ";
}
