#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> r;
pair<int, int> g(int x) {
    if(x == d[x]) return {0, x};
    else {
        auto rt = g(d[x]);
        r[x] += rt.first;
        d[x] = rt.second;
        return {r[x], d[x]};
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    d.resize(n + 1);
    r.resize(n + 1);
    for (int i = 1; i <= n; ++i) d[i] = i;
    while (m--) {
        int op; cin >> op;
        if(op == 1) {
            int a, b;
            cin >> a >> b;
            r[a] = r[b] + 1;
            d[a] = b;
        } else {
            int a; cin >> a;
            cout << g(a).first << "\n";
        }
    }
}
