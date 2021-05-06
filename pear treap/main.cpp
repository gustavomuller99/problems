#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
#define ll unsigned long long
struct Treap {
    int p, ss;
    char d;
    ll h;
    vector<Treap*> c;
    Treap(char d);
};
int size(Treap *t) { return t==nullptr?0:t->ss; }
void recalc(Treap *t) {
    if(t == nullptr) return;
    t->ss = 1;
    if(t->c[0] != nullptr) t->h = (t->c[0]->ss + 1) * t->d;
    else t->h = t->d;
    for(Treap* p : t->c) if(p!=nullptr) t->h += p->h;
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
Treap::Treap(char d) {
    this->c = {nullptr, nullptr};
    this->d = d;
    this->p = mt() % 500000;
    this->h = d;
    recalc(this);
}
void walk(Treap* t, string& a) {
    if(t->c[0] != nullptr) walk(t->c[0], a);
    a += t->d;
    if(t->c[1] != nullptr) walk(t->c[1], a);
}
int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,q; cin>>n>>q;
    string in; cin>>in;
    Treap *t = nullptr, *rv = nullptr;
    for(char c : in) { t = merge(t, new Treap(c)); }
    for(char c : in) { rv = merge(new Treap(c), rv); }
    for (int i = 0; i < q; ++i) {
        int o; cin>>o;
        if(o==1) {
            int l,r; cin>>l>>r; l--, r--;
            vector<Treap*> r1 = split(t, r+1);
            vector<Treap*> r2 = split(r1[0], l);
            t = merge(r2[0], r1[1]);

            int sz = size(rv);
            r1 = split(rv, sz-l);
            r2 = split(r1[0], sz-r-1);
            rv = merge(r2[0], r1[1]);
        } else if(o==2) {
            char c; int r; cin>>c>>r; r--;
            vector<Treap*> r1 = split(t, r);
            t = merge(r1[0], new Treap(c));
            t = merge(t, r1[1]);

            r1 = split(rv, size(rv)-r);
            rv = merge(r1[0], new Treap(c));
            rv = merge(rv, r1[1]);

        } else {
            string z;
            int l, r; cin>>l>>r; l--,r--;
            vector<Treap*> r1 = split(t, r+1);
            vector<Treap*> r2 = split(r1[0], l);
            ll h1 = r2[1]->h;

            walk(r2[1], z);
            cout << z << " " << h1 << "\n";

            t = merge(r2[0], merge(r2[1], r1[1]));

            int sz = size(rv);
            r1 = split(rv, sz-l);
            r2 = split(r1[0], sz-r-1);
            ll h2 = r2[1]->h;

            z = "";
            walk(r2[1], z);
            cout << z << " " << h2 << "\n\n";

            rv = merge(r2[0], merge(r2[1], r1[1]));

            if(h1==h2) cout << "yes\n";
            else cout << "no\n";
        }
    }
}

