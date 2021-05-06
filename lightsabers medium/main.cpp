#include <bits/stdc++.h>
using namespace std;
vector<int> c, a, am; int n, m, bok = 0; bool f(int w) {
    am = vector<int> (m);
    int ok = bok; int i = 0;
    bool r = false;
    while(i != n) {
        int k1 = c[i] - 1;
        am[k1]++;
        if(am[k1] == a[k1]) ok++;
        if(i-w >= 0) {
            int k2 = c[i-w] - 1;
            if(am[k2] == a[k2]) ok--;
            am[k2]--;
        }
        if(ok == m) r = true;
        i++;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    int l, r, s = 0;
    c.resize(n); a.resize(m);
    for (int i = 0; i < n; ++i) cin>>c[i];
    for (int i = 0; i < m; ++i) cin>>a[i], s += a[i], (a[i] == 0 ? bok++ : bok);
    l = s-1; r = n+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    if(r == n+1) cout << -1;
    else cout << r - s;
}
