#include <bits/stdc++.h>
using namespace std;
vector<int> pa, pb;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    pa.resize(n + 1); pb.resize(n + 1);
    pa[0] = 0; pb[0] = 0;
    for (int i = 1; i <= n; ++i) { int k; cin >> k; pa[i] = (k%2) + pa[i - 1]; }
    for (int i = 1; i <= n; ++i) { int k; cin >> k; pb[i] = (k%2) + pb[i - 1]; }
    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(a < c) swap(a, c);
        if(b < d) swap(b, d);
        int nd = (a-c+1) + (b-d+1);
        int h = (pa[a] - pa[c-1]) + (pb[b] - pb[d-1]);
        if(h == 0 || h == nd) cout << "YES\n";
        else cout << "NO\n";
    }
}
