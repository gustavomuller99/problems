#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n, ans = 0; ll k, c = 1, c2 = 0; bool c1 = true;
vector<vector<int>> t;
vector<bool> vis;
vector<int> d;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>k;
    int p = 1, pp = 1;
    while(p < k) {
        c += pp * 3, pp *= 3, p++;
        if(c > n) break;
    }
    t.resize(n); vis.resize(n); d.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin>>u>>v; u--,v--;
        t[u].push_back(v); t[v].push_back(u);
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) if(t[i].size() == 1) q.push(i);
    while(!q.empty()) {
        int r = q.front();
        q.pop();
        if(vis[r]) continue;
        vis[r] = true;
        if(d[r] < 3 && d[r] != 0) c1 = false;
        else if(d[r] != 0) ans++;
        int cnt = 0;
        for(int adj : t[r]) {
            if(!vis[adj]) d[adj]++, q.push(adj), cnt++;
        }
        if(cnt == 0) c2++;
    }
    if(ans > 1 && c == 1) cout << "No";
    else if(ans >= c && c1 && c2 == 1) cout << "Yes";
    else cout << "No";
}
