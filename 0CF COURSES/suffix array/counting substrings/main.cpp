#include <bits/stdc++.h>
using namespace std;
int q;
string s;
vector<int> suf;
void radix_sort(vector<pair<pair<int,int>, int>> &r) {
    int n = r.size();
    {
        vector<int> cnt(n);
        for (auto x : r) {
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int>> r_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : r) {
            int i = x.first.second;
            r_new[pos[i]] = x;
            pos[i]++;
        }
        r = r_new;
    }
    {
        vector<int> cnt(n);
        for(auto x : r) {
            cnt[x.first.first]++;
        }
        vector<pair<pair<int,int>, int>> r_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i-1] + cnt[i-1];
        }
        for(auto x : r) {
            int i = x.first.first;
            r_new[pos[i]] = x;
            pos[i]++;
        }
        r = r_new;
    }
}
void build() {
    s += '$';
    int n; n = s.size();
    vector<pair<char, int>> a(n);
    vector<int> c(n);
    // k = 0
    for(int i = 0; i < n; i++) {
        a[i].first = s[i];
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    c[a[0].second] = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].first == a[i-1].first) c[a[i].second] = c[a[i-1].second];
        else c[a[i].second] = c[a[i-1].second] + 1;
    }

    // k -> k+1
    int k = 0;
    vector<pair<pair<int,int>, int>> p(n);
    while((1ULL << k) < n) {
        for(int i = 0; i < n; i++) {
            p[i].first = {c[i], c[(i + (1ULL << k)) % n]};
            p[i].second = i;
        } radix_sort(p);
        c[p[0].second] = 0;
        for(int i = 1; i < n; i++) {
            if (p[i].first == p[i - 1].first) c[p[i].second] = c[p[i - 1].second];
            else c[p[i].second] = c[p[i - 1].second] + 1;
        }
        k++;
    }
    suf.resize(n);
    for (int i = 0; i < n; ++i) {
        suf[i] = p[i].second;
    }
}
bool f(int x, string& query) {
    return s.substr(suf[x], query.size()) <= query;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> q;
    build();

    while(q--) {
        string query;
        cin >> query;
        string c = query;
        query += '$';
        int l = -1, r = s.size();
        while (r > l + 1) {
            int mid = (l + r) / 2;
            if(f(mid, query)) l = mid;
            else r = mid;
        }
        int lo = l;
        query[query.size()-1] = '~';
        l = -1, r = s.size();
        while (r > l + 1) {
            int mid = (l + r) / 2;
            if(f(mid, query)) l = mid;
            else r = mid;
        }
        int hi = l;
        if(lo == hi && s.substr(suf[lo], c.size()) != c) cout << 0 << "\n";
        else cout << hi - lo + 1 << "\n";
    }
}
