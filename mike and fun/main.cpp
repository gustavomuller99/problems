#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, q; cin>>n>>m>>q;
    vector<int> d(n);
    int g[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin>>g[i][j];
    }
    for (int i = 0; i < n; ++i) {
        int mx = 0, cnt = 0;
        for (int j = 0; j < m; ++j) {
            if(g[i][j] == 1) cnt++;
            else cnt = 0;
            mx = max(mx, cnt);
        }
        d[i] = mx;
    }
    while(q--) {
        int x,y,ans=0; cin>>x>>y; x--,y--;
        g[x][y] = !g[x][y];
        int mx = 0, cnt = 0;
        for (int i = 0; i < m; ++i) {
            if(g[x][i] == 1) cnt++;
            else cnt = 0;
            mx = max(mx, cnt);
        }
        d[x] = mx;
        for (int i = 0; i < n; ++i) ans = max(ans, d[i]);
        cout << ans << "\n";
    }
}
