#include <bits/stdc++.h>
using namespace std;
vector<string> g;
vector<vector<int>> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int r, c; cin >> r >> c;
    g.resize(r);
    v.resize(r, vector<int>(c));
    for (int i = 0; i < r; ++i) cin >> g[i];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; ++j) {
            int k = 0;
            if(i > 0) { k+= v[i-1][j]; if(g[i][j] == '.' && g[i-1][j] == '.') k++; }
            if(j > 0) { k+= v[i][j-1]; if(g[i][j] == '.' && g[i][j-1] == '.') k++; }
            if(i > 0 && j > 0) { k -= v[i-1][j-1]; }
            v[i][j] = k;
        }
    }
    int q; cin >> q; while(q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        int ans = v[r2][c2] - v[r1][c2] - v[r2][c1] + v[r1][c1];
        for (int i = r2; i > r1; --i) if(g[i][c1] == '.' && g[i-1][c1] == '.') ans++;
        for (int i = c2; i > c1; --i) if(g[r1][i] == '.' && g[r1][i-1] == '.') ans++;
        cout << ans << "\n";
    }
}
