#include <bits/stdc++.h>
using namespace std;
vector<set<int>> g;
vector<int> d;
string ans;
void dfs(int i, int f) {
    ans += (i+'a');
    for(int adj : g[i]) {
        if(adj == f) continue;
        dfs(adj, i);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string in; cin >> in;
        g = vector<set<int>>(26);
        d = vector<int>(26);
        int diff = 0;
        for (int i = 1; i < in.size(); ++i) {
            int a = in[i-1] - 'a', b = in[i] - 'a';
            if(d[a] == 0) diff++;
            if(d[b] == 0) diff++;
            if(!g[a].count(b)) { g[a].insert(b); d[a]++; }
            if(!g[b].count(a)) { g[b].insert(a); d[b]++; }
        }
        ans = "";
        int b, x = 0, y = 0;
        for (int i = 0; i < 26; ++i) {
            if(d[i] == 1) x++, b = i;
            else if(d[i] == 2) y++;
        }
        if((x != 2 || y != diff - 2) && in.size() > 1) cout << "NO" << "\n";
        else {
            if(in.size() > 1) dfs(b,b);
            for (int i = 0; i < 26; ++i) {
                if(d[i] == 0) ans += (i+'a');
            }
            cout << "YES\n" << ans << "\n";
        }
    }
}
