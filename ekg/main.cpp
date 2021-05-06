#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<list<int>> q;
bool dp[1001][1001] = {false};
int g(int u) {
    return d[u] = (d[u] == u ? u : g(d[u]));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    d.resize(n + 1);
    q.resize(n + 1);
    for (int i = 1; i <= n; ++i) { d[i] = i; q[i].push_back(i); }
    for (int i = 1; i <= n; ++i) {
        int c; cin >> c;
        if(c != 0) {
            c = g(c);
            q[c].splice(q[c].end(), q[i], q[i].begin(), q[i].end());
            d[i] = c;
        }
    }
    int s = g(x);
    int pos = 0;
    for(int k : q[s]) { pos++; if(k == x) break; }
    set<pair<int, int>> sz;
    for (int i = 1; i <= n; ++i) {
        int r = g(i);
        if(r != s && !sz.count({q[r].size(), r})) sz.insert({q[r].size(), r});
    }
    cout << pos << "\n";
    int ii = 1;
    for (int i = 0; i <= sz.size(); ++i) dp[i][0] = true;
    for(auto i : sz) {
        for (int j = 0; j <= 1000; ++j) {
            if(i.first > j) dp[ii][j] = dp[ii-1][j];
            else dp[ii][j] = dp[ii-1][j] | dp[ii-1][j-i.first];
        }
        ii++;
    }
    for(int i = 1; i <= 1000; ++i) {
        if(dp[sz.size()][i]) cout << pos + i << "\n";
    }
}
