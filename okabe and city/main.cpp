#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans = INT_MAX;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m>>k;
    bool grid[n][m]; memset(grid, false, sizeof(grid));
    for (int i = 0; i < k; ++i) { int r,c; cin>>r>>c; r--,c--; grid[r][c] = true; }
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {0,0}});
    grid[0][0] = false;
    while(!q.empty()) {
        auto r = q.top(); int i = r.second.first, j = r.second.second, v = r.first;
        q.pop();
        grid[i][j] = false;
        if(i == n-1 && j == m-1) { ans = v; break; }
        if(i > 0 && grid[i-1][j]) q.push({v, {i-1, j}});
        if(i < n-1 && grid[i+1][j]) q.push({v, {i+1, j}});
        if(j > 0 && grid[i][j-1]) q.push({v, {i, j-1}});
        if(j < m-1 && grid[i][j+1]) q.push({v, {i, j+1}});
        if(i < n-1 && j < m-1 && grid[i+1][j+1]) q.push({v-1, {i+1, j+1}});
        if(i > 0 && j < m-1 && grid[i-1][j+1]) q.push({v-1, {i-1, j+1}});
        if(i < n-1 && j > 0 && grid[i+1][j-1]) q.push({v-1, {i+1, j-1}});
        if(i > 0 && j > 0 && grid[i-1][j-1]) q.push({v-1, {i-1, j-1}});
        for (int i1 = i+2; i1 < n; ++i1) for (int j1 = j-2; j1 <= j+2; ++j1) if(j1 >= 0 && j1 <= m-1 && grid[i1][j1]) q.push({v-1, {i1, j1}});
        for (int i1 = i-2; i1 >= 0; --i1) for (int j1 = j-2; j1 <= j+2; ++j1) if(j1 >= 0 && j1 <= m-1 && grid[i1][j1]) q.push({v-1, {i1, j1}});
        for (int j1 = j+2; j1 < m; ++j1) for (int i1 = i-2; i1 <= i+2; ++i1) if(i1 >= 0 && i1 <= n-1 && grid[i1][j1]) q.push({v-1, {i1, j1}});
        for (int j1 = j-2; j1 >= 0; --j1) for (int i1 = i-2; i1 <= i+2; ++i1) if(i1 >= 0 && i1 <= n-1 && grid[i1][j1]) q.push({v-1, {i1, j1}});
        if(!grid[n-1][m-1]) {
            if(abs(i - (n-1)) < 2) q.push({v-1, {n-1, m-1}});
            if(abs(j - (m-1)) < 2) q.push({v-1, {n-1, m-1}});
        }
    }
    if(ans == INT_MAX) cout << -1;
    else cout << -ans;
}