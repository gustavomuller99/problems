#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> g;
int n, m;
bool dfs(int i=0, int j=0) {
    if(i == n-1 && j == m-1) return true;
    if(i >= n || j >= m || !g[i][j]) return false;
    g[i][j] = false;
    if(dfs(i+1, j)) return true;
    if(dfs(i, j+1)) return true;
    return false;
}
int main() {
    cin>>n>>m;
    g.resize(n, vector<bool> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin>>c;
            g[i][j] = c == '.';
        }
    }
    int ans = 0;
    while(dfs()) {
        ans++;
        g[0][0] = true;
    }
    cout << ans;
}
