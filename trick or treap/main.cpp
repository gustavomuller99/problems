#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
struct Treap {
    int d, p, ss;
    unsigned long long sum;
    Treap* parent;
    vector<Treap*> c;
    Treap(int d);
};
int size(Treap *t) { return t==nullptr?0:t->ss; }
void recalc(Treap *t) {
    if(t == nullptr) return;
    t->ss = 1;
    t->sum = t->d;
    for(Treap* p : t->c) if(p!=nullptr) t->ss += p->ss;
    for(Treap* p : t->c) if(p!=nullptr) t->sum += p->sum;
}
vector<Treap*> split(Treap* t, int left) {
    if(t == nullptr) return {nullptr, nullptr};
    if(size(t->c[0]) >= left) {
        vector<Treap*> r = split(t->c[0], left);
        if(t->c[0] != nullptr) t->c[0]->parent = nullptr;
        t->c[0] = r[1];
        if(r[1] != nullptr) r[1]->parent = t;
        recalc(t);
        return {r[0], t};
    } else {
        vector<Treap*> r = split(t->c[1], left - size(t->c[0]) - 1);
        if(t->c[1] != nullptr) t->c[1]->parent = nullptr;
        t->c[1] = r[0];
        if(r[0] != nullptr) r[0]->parent = t;
        recalc(t);
        return {t, r[1]};
    }
}
Treap* merge(Treap* l, Treap* r) {
    if(l == nullptr) return r;
    if(r == nullptr) return l;
    if(l->p < r->p) {
        if(l->c[1] != nullptr) l->c[1]->parent = nullptr;
        l->c[1] = merge(l->c[1], r);
        if(l->c[1] != nullptr) l->c[1]->parent = l;
        recalc(l);
        return l;
    } else {
        if(r->c[0] != nullptr) r->c[0]->parent = nullptr;
        r->c[0] = merge(l, r->c[0]);
        if(r->c[0] != nullptr) r->c[0]->parent = r;
        recalc(r);
        return r;
    }
}
Treap* r(Treap* p) {
    if(p->parent != nullptr) return r(p->parent);
    return p;
}
Treap::Treap(int d) {
    this->c = {nullptr, nullptr};
    this->d = d;
    this->p = mt() % 500000;
    this->sum = d;
    this->parent = nullptr;
    recalc(this);
}
void walk(Treap* t) {
    if(t->c[0] != nullptr) walk(t->c[0]);
    cout << t->d + 1 << " ";
    if(t->c[1] != nullptr) walk(t->c[1]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int q; cin>>q;
    map<int,Treap*> mp;
    for (int i = 1; i <= q; ++i) {
        int o;
        cin >> o;
        if (o == 1) {
            int y;
            cin >> y;
            mp[i] = new Treap(y);
        } else if (o == 2) {
            int y, z;
            cin >> y >> z;
            Treap *r1 = r(mp[y]);
            Treap *r2 = r(mp[z]);
            if (r1 != r2) merge(r1, r2);
        } else if (o == 3) {
            int y, z;
            cin >> y >> z;
            Treap *r1 = r(mp[y]);
            if (r1->ss > z) split(r1, z);
        } else if (o == 4) {
            int y;
            cin >> y;
            Treap *r1 = r(mp[y]);
            cout << r1->sum << "\n";
        }
    }
}
