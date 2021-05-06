#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> u;
vector<vector<int>> t;
long long ans = 0;
void dfs(int x, int f = -1) {
    for(int adj : t[x]) {
        if(adj==f) continue;
        dfs(adj, x);
        u[x] += u[adj];
    }
    ans += min(u[x], 2*k - u[x]);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>k;
    u.resize(n); t.resize(n);
    for (int i = 0; i < 2*k; ++i) {int x; cin>>x; x--,u[x]++;}
    for (int i = 0; i < n-1; ++i) {
        int x,y;cin>>x>>y; x--,y--;
        t[x].push_back(y); t[y].push_back(x);
    }
    dfs(0);
    cout << ans;
}
