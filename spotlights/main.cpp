#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<vector<int>> r(n, vector<int> {INT_MAX, INT_MIN}), c(m, vector<int> {INT_MAX, INT_MIN});
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int k; cin >> k;
            if(!k) p.emplace_back(i, j);
            else {
                if(j < r[i][0]) r[i][0] = j;
                if(j > r[i][1]) r[i][1] = j;
                if(i < c[j][0]) c[j][0] = i;
                if(i > c[j][1]) c[j][1] = i;
            }
        }
    }
    int ans = 0;
    for(auto k : p) {
        if(r[k.first][0] < k.second) ans++;
        if(r[k.first][1] > k.second) ans++;
        if(c[k.second][0] < k.first) ans++;
        if(c[k.second][1] > k.first) ans++;
    }
    cout << ans;
}
