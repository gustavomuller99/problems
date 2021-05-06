#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    vector<pair<ll,ll>> c(n);
    vector<pair<ll, pair<ll,ll>>> f(m);
    vector<bitset<1000>> a(n);
    bitset<1000> r;
    int d[n][n];
    for (int i = 0; i < n; ++i) cin>>c[i].first>>c[i].second;
    for (int i = 0; i < m; ++i) cin>>f[i].first>>f[i].second.first>>f[i].second.second;
    for (int i = 0; i < n; ++i) {
        ll x = c[i].first, y = c[i].second;
        for (int j = 0; j < m; ++j) {
            ll xc = f[j].second.first, yc = f[j].second.second, ra = f[j].first;
            if(sqrt((x - xc)*(x - xc) + (y - yc)*(y - yc)) - (double) ra < 1e-8) a[i].set(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            r = a[i] ^ a[j];
            d[i][j] = d[j][i] = r.count();
        }
    }
    for (int i = 0; i < k; ++i) {
        int x, y; cin>>x>>y; x--, y--;
        cout << d[x][y] << "\n";
    }
}
