#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, ll>> s;
ll l, r;
pair <int,ll> rec(int lx, int rx, int i) {
    if(lx >= l && rx < r) return s[i];
    if(rx < l || lx >= r) return {1, LLONG_MAX};

    int mid = (lx + rx) / 2;
    pair<int, ll> p1 = rec(lx, mid, i*2 + 1);
    pair<int, ll> p2 = rec(mid+1, rx, i*2 + 2);
    pair<int, ll> p = (p1.second > p2.second) ? p2 : p1;
    if(p2.second == p1.second) {
        return make_pair(p.first + p2.first, p1.second);
    } else return p;
}
int main() {
    ios::sync_with_stdio(false);
    int n, m, k = 1; cin >> n >> m;

    while(k < n) {
        k*=2;
    } k*=2; k--;

    s.resize(k, {1, LLONG_MAX});

    for (int i = k/2; i < k/2 + n; ++i) {
        ll p; cin >> p;
        s[i] = {1, p};
    }

    for (int i = k/2 - 1; i >= 0; --i) {
        pair<int, ll> p = (s[i*2 + 1].second > s[i*2 + 2].second) ? s[i*2 + 2] : s[i*2 + 1];
        if(s[i*2 + 1].second == s[i*2 + 2].second) {
            s[i] = {p.first + s[i*2 + 2].first, p.second};
        } else {
            s[i] = p;
        }
    }

    while(m--) {
        int o; cin >> o >> l >> r;
        if(o == 1) {
            int i = k/2 + (int) l;
            ll v = r; s[i] = {1, v};
            while(i != 0) {
                i = i/2 - (i%2 == 0);
                pair<int, ll> p = (s[i*2 + 1].second > s[i*2 + 2].second) ? s[i*2 + 2] : s[i*2 + 1];
                if(s[i*2 + 1].second == s[i*2 + 2].second) {
                    s[i] = {p.first + s[i*2 + 2].first, p.second};
                } else {
                    s[i] = p;
                }
            }
        } else {
            pair<int, ll> p = rec(0, k/2, 0);
            cout << p.second << " " << p.first << endl;
        }
    }
}
