#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
struct Treap {
    int d, p, ss;
    vector<Treap*> c;
    Treap(int d);
};
int size(Treap *t) { return t==nullptr?0:t->ss; }
void recalc(Treap *t) {
    if(t == nullptr) return;
    t->ss = 1;
    for(Treap* p : t->c) if(p!=nullptr) t->ss += p->ss;
}
vector<Treap*> split(Treap* t, int left) {
    if(t == nullptr) return {nullptr, nullptr};
    if(size(t->c[0]) >= left) {
        vector<Treap*> r = split(t->c[0], left);
        t->c[0] = r[1];
        recalc(t);
        return {r[0], t};
    } else {
        vector<Treap*> r = split(t->c[1], left - size(t->c[0]) - 1);
        t->c[1] = r[0];
        recalc(t);
        return {t, r[1]};
    }
}
Treap* merge(Treap* l, Treap* r) {
    if(l == nullptr) return r;
    if(r == nullptr) return l;
    if(l->p < r->p) {
        l->c[1] = merge(l->c[1], r);
        recalc(l);
        return l;
    } else {
        r->c[0] = merge(l, r->c[0]);
        recalc(r);
        return r;
    }
}
Treap::Treap(int d) {
    this->c = {nullptr, nullptr};
    this->d = d;
    this->p = mt() % 500000;
    recalc(this);
}
void walk(Treap* t) {
    if(t->c[0] != nullptr) walk(t->c[0]);
    cout << t->d + 1 << " ";
    if(t->c[1] != nullptr) walk(t->c[1]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    Treap *t = nullptr;
    for (int i = 0; i < n; ++i) {
        t = merge(t, new Treap(i));
    }
    for (int i = 0; i < n; ++i) {
        int a,b; cin>>a>>b; a--, b--;
        if(a >= b) continue;
        int sz = min(n-b, b-a);
        vector<Treap*> r1 = split(t, b);
        vector<Treap*> r2 = split(r1[0], a);
        vector<Treap*> r3 = split(r2[1], sz);
        vector<Treap*> r4 = split(r1[1], sz);
        t = merge(r2[0], merge(r4[0], merge(r3[1], merge(r3[0], r4[1]))));
    }
    walk(t);
}
