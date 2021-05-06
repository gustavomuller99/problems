#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

int main() {
    int n, m; cin >> n >> m;
    vector<string> in(n);
    vector<pair<string, string>> d(m);
    for (int i = 0; i < n; ++i) cin >> in[i];
    sort(in.begin(), in.end());
    for (int i = 0; i < n; ++i) mp[in[i]] = i;
    for (int i = 0; i < m; ++i) cin >> d[i].first >> d[i].second;
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        bool p = true;
        for (int j = 0; j < m; ++j) {
            if((i & (1 << mp[d[j].first])) && (i & (1 << mp[d[j].second]))) {p = false; break;}
        }
        if(p && __builtin_popcount(ans) < __builtin_popcount(i)) ans = i;
    }
    cout << __builtin_popcount(ans) << "\n";
    for (int i = 0; i < n; ++i) {
        if(ans & (1 << mp[in[i]])) cout << in[i] << "\n";
    }
}
