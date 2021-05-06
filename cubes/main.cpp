#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n);
    vector<vector<pair<int,int>>> d(m);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        int l = i, c = a[i];
        while(i != n-1 && a[i+1] == a[i]) i++;
        d[c-1].push_back({l,i});
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if(d[i].empty()) continue;
        int l = 0, r = 0, v = d[i][0].second - d[i][0].first + 1, dl = k;
        ans = max(ans, v);
        while(r != d[i].size() - 1) {
            r++;
            v += d[i][r].second - d[i][r].first + 1;
            dl -= (d[i][r].first - d[i][r-1].second - 1);
            while(dl < 0) {
                v -= (d[i][l].second - d[i][l].first + 1);
                l++;
                dl += d[i][l].first - d[i][l-1].second - 1;
            }
            ans = max(ans, v);
        }
    }
    cout << ans;
}
