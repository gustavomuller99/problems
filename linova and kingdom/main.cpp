#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> g;
vector<pair<int,int>> d;
int dfs(int n, int f = -1, int dist = -1) {
    d[n].first = dist + 1;
    for (int i = 0; i < g[n].size(); ++i) {
        if(g[n][i] != f) {
            d[n].second += dfs(g[n][i], n, dist + 1);
        }
    }
    return d[n].second + 1;
}
bool comp(const pair<int,int> x, const pair<int,int> y) {
    return (x.first - x.second > y.first - y.second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    g.resize(n);
    d.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    sort(d.begin(), d.end(), comp);
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += d[i].first - d[i].second;
    }
    cout << ans << endl;
}
