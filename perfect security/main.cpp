#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
struct nd {
    bool e = false;
    nd *r = nullptr, *l = nullptr;
};
void insert(nd *n, ll a) {
    if(a==0) return;
    int r = a % 2;
    if(r) {
        if(n->l == nullptr) n->l = new nd;
        insert(n->l, a >> 1);
    } else {
        if(n->r == nullptr) n->r = new nd;
        insert(n->r, a >> 1);
    }
}
pair<ll, bool> search(nd *n, ll s, ll d = 0, int sh = 0) {

}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<ll> a(n), ans;
    nd *root = new nd;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        ll x; cin>>x; insert(root, x);
    }
    for(ll x : a) {
        auto d = search(root, x);
        cout << "\n";
        ans.push_back(d.first);
    }
    for(ll x : ans) cout << x << " ";
}
