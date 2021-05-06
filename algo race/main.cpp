#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m,r; cin>>n>>m>>r;
    int d[n][n][n+1], a[n][n][m];
    memset(d, 1e6+3, sizeof(d));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) cin>>a[j][k][i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                for (int l = 0; l < n; ++l)
                    a[k][l][i] = min(a[k][l][i], a[k][j][i] + a[j][l][i]);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                d[j][k][0] = min(d[j][k][0], a[j][k][i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                for (int l = 0; l < n; ++l)
                    d[k][l][i] = min(d[k][l][i], d[k][j][i - 1] + d[j][l][0]);
    }
    for (int i = 0; i < r; ++i) {
        int u, v, c; cin>>u>>v>>c; u--,v--;
        cout << d[u][v][min(n, c)] << "\n";
    }
}
