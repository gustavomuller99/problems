#include <bits/stdc++.h>
using namespace std;
vector<int> d, t;
int n, m;
struct mk {int l, r; bool lc, rc; vector<int> h;};
vector<pair<int, int>> op;
vector<mk> a;
vector<bool> v;
int g(int u) { return d[u] = (d[u] == u ? u : g(d[u])); }
void dfs1(int i) {
    v[i] = true;
    if(a[i].r != -1 && a[i].rc && !v[a[i].r]) { d[a[i].r] = i; dfs1(a[i].r); }
    if(a[i].l != -1 && a[i].lc && !v[a[i].l]) { d[a[i].l] = i; dfs1(a[i].l); }
    for(int adj : a[i].h) {
        if((a[adj].r == i && a[adj].rc && !v[adj]) || (a[adj].l == i && a[adj].lc && !v[adj])) { d[adj] = i; dfs1(adj); }
    }
}
void dfs2(int i, int time) {
    t[i] = time;
    if(a[i].r != -1 && a[i].rc && t[a[i].r] == -1) dfs2(a[i].r, m);
    if(a[i].l != -1 && a[i].lc && t[a[i].l] == -1) dfs2(a[i].l, m);
    for(int adj : a[i].h) {
        if((a[adj].r == i && a[adj].rc && t[adj] == -1) || (a[adj].l == i && a[adj].lc && t[adj] == -1)) dfs2(adj, m);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    d.resize(n + 1); t.resize(n + 1, -1); a.resize(n + 1); op.resize(m);
    v.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) d[i] = i;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        a[i].l = l; a[i].r = r;
        a[i].lc = a[i].rc = true;
        if(r != -1) a[r].h.push_back(i);
        if(l != -1) a[l].h.push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int p, h;
        cin >> p >> h;
        op[i] = {p, h};
        if(h == 1) a[p].lc = false;
        else a[p].rc = false;
    }
    for (int i = 1; i <= n; ++i) {
        if(!v[i]) dfs1(i);
    }
    m--;
    for (auto i = op.rbegin(); i < op.rend(); ++i) {
        int x = i->first, y = (i->second == 1 ? a[x].l : a[x].r);
        int fx = g(x), fy = g(y);
        if(fx == 1 && fx != fy) dfs2(fy, m);
        else if(fy == 1 && fx != fy) dfs2(fx, m);
        (i->second == 1 ? a[x].lc = true : a[x].rc = true);
        if(fx == 1) swap(fx, fy);
        d[fx] = fy;
        m--;
    }
    for(int i = 1; i <= n; ++i) cout << t[i] << "\n";
}
