#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; ll sum = 0; cin>>n;
        vector<pair<int, vector<int>>> g(n);
        vector<ll> ans;
        for (int i = 0; i < n; ++i) cin >> g[i].first, sum += g[i].first;
        ans.push_back(sum);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin>>u>>v; u--, v--;
            g[u].second.push_back(v);
            g[v].second.push_back(u);
        }
        sort(g.begin(), g.end(), greater<>());
        int k1 = 1, k2 = 0;
        while(k1 != n - 1) {
            sum = ans[k1 - 1];
            for (int i = 1; i < g[k2].second.size(); ++i) {
                sum += g[k2].first;
                ans.push_back(sum);
                k1++;
            }
            k2++;
        }
        for(ll x : ans) cout << x << " ";
        cout << "\n";
    }
}
