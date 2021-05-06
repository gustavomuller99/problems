#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod;
struct m2 {
   ll a1, a2, a3, a4;
};
m2 mult(m2 a, m2 b) {
    m2 c;
    c.a1 = ((a.a1)*(b.a1) + (a.a2)*(b.a3))%mod;
    c.a2 = ((a.a1)*(b.a2) + (a.a2)*(b.a4))%mod;
    c.a3 = ((a.a3)*(b.a1) + (a.a4)*(b.a3))%mod;
    c.a4 = ((a.a3)*(b.a2) + (a.a4)*(b.a4))%mod;
    return c;
}
vector<m2> t;
m2 rec(int l, int r, int lx, int rx, int n = 0) {
    if(lx >= l && rx <= r) return t[n];
    if(rx < l || lx > r) return {1,0,0,1};

    int mid = (lx + rx) / 2;
    return mult(rec(l, r, lx, mid, 2*n + 1), rec(l, r, mid + 1, rx, 2*n + 2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k = 1;
    cin >> mod >> n >> m;
    while (k < n) k *= 2;
    k *= 2;
    k--;
    t.resize(k, {1,0,0,1});
    for (int i = k/2; i < k/2 + n; ++i) {
        cin >> t[i].a1 >> t[i].a2 >> t[i].a3 >> t[i].a4;
    }
    for (int i = k/2 - 1; i >= 0; --i) {
        t[i] = mult(t[i*2 + 1], t[i*2 + 2]);
    }
    while(m--) {
        int lx, rx; cin >> lx >> rx;
        lx--; rx--;
        m2 ans = rec(lx, rx, 0, k/2);
        cout << ans.a1 << " " << ans.a2 << "\n";
        cout << ans.a3 << " " << ans.a4 << "\n\n";
    }
}
