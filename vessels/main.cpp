#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> a, am;
vector<int> d;
int g(int u) { return d[u] = d[u] == u ? u : g(d[u]); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,q; cin>>n;
    a.resize(n); am.resize(n); d.resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < n; ++i) cin>>a[i];
    cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t==1) {
            ll x; int k; cin>>k>>x;k--;
            k = g(k);
            while(x > 0) {
                ll xc = x;
                x -= min(x, a[k] - am[k]);
                am[k] = min(a[k], am[k] + xc);
                if(k == n-1) break;
                int nxt = g(k+1);
                if(am[k] == a[k]) d[k] = nxt;
                k = nxt;
            }
        } else {
            int k;cin>>k;k--;
            cout << am[k] << "\n";
        }
    }
}
