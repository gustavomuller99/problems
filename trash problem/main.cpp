#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    set<int> a;
    set<pair<ll, pair<ll,ll>>> gap;
    for (int i = 0; i < n; ++i) {
        ll x; cin>>x; a.insert(x);
    }
    ll p = *a.begin();
    for(ll x : a) {
        gap.insert({x-p, {p, x}});
        p = x;
    } gap.erase({0, {*a.begin(), *a.begin()}});
    if(a.size()<=1) cout << 0 << "\n";
    else cout << (gap.rbegin()->second.first - *a.begin()) + (*a.rbegin() - gap.rbegin()->second.second) << "\n";
    while(q--) {
        int o; ll x; cin>>o>>x;
        if(o) {
            if(a.empty()) {}
            else if(x < *a.begin()) {
                gap.insert({*a.begin() - x, {x, *a.begin()}});
            } else if (x > *a.rbegin()) {
                gap.insert({x - *a.rbegin(), {*a.rbegin(), x}});
            } else {
                auto it = a.upper_bound(x);
                ll after = *it; it--;
                ll before = *it;
                gap.erase({after-before, {before, after}});
                gap.insert({x - before, {before, x}}); gap.insert({after - x, {x, after}});
            }
            a.insert(x);
        } else {
            if(a.size()<=1) {}
            else if(x == *a.begin()) {
                gap.erase({*(++a.begin()) - *a.begin(), {*a.begin(), *(++a.begin())}});
            } else if(x == *a.rbegin()) {
                gap.erase({*a.rbegin() - *(--a.rbegin()), {*(--a.rbegin()), *a.rbegin()}});
            } else {
                auto it = a.upper_bound(x);
                ll after = *it; it--, it--;
                ll before = *it;
                gap.erase({x-before, {before, x}}); gap.erase({after-x, {x, after}});
                gap.insert({after-before, {before, after}});
            }
            a.erase(x);
        }
        if(a.size() <= 1) cout << 0 << "\n";
        else cout << (gap.rbegin()->second.first - *a.begin()) + (*a.rbegin() - gap.rbegin()->second.second) << "\n";
    }
}
