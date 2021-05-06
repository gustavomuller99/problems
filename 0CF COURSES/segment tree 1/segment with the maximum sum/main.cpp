#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll seg; ll suf; ll pre; ll sum;
};
vector<node> t(1e6, {0ll,0ll,0ll,0ll});
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k<n) {k*=2;} k*=2; k--;
    for (int i = k/2; i < k/2 + n; ++i) {
        ll p; cin >> p;
        t[i] = {p,p,p,p};
    }
    for (int i = k/2 - 1; i >= 0; --i) {
        node p1 = t[i*2 + 1];
        node p2 = t[i*2 + 2];
        node p;
        p.sum = p1.sum + p2.sum;
        p.seg = max(p1.seg, max(p2.seg, p1.suf + p2.pre));
        p.pre = max(p1.pre, p1.sum + p2.pre);
        p.suf = max(p2.suf, p2.sum + p1.suf);
        t[i] = p;
    }
    cout << max(t[0].sum, max(t[0].suf, max(t[0].pre, max(t[0].seg, 0LL)))) << endl;
    for (int i = 0; i < m; ++i) {
        int index; ll v;
        cin >> index >> v;
        index = k/2 + index;
        t[index] = {v,v,v,v};
        while(index != 0) {
            index = index/2 - (index%2 == 0);
            node p1 = t[index*2 + 1];
            node p2 = t[index*2 + 2];
            node p;
            p.sum = p1.sum + p2.sum;
            p.seg = max(p1.seg, max(p2.seg, p1.suf + p2.pre));
            p.pre = max(p1.pre, p1.sum + p2.pre);
            p.suf = max(p2.suf, p2.sum + p1.suf);
            t[index] = p;
        }
        cout << max(t[0].sum, max(t[0].suf, max(t[0].pre, max(t[0].seg, 0LL)))) << endl;
    }
}
