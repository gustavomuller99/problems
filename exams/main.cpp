#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> p;
vector<int> d;
int n, m;
int f(int x) {
    set<pair<int, int>> s;
    for (int i = 1; i <= m; ++i) {
        auto pt = upper_bound(p[i].begin(), p[i].end(), x);
        if(pt == p[i].begin()) return false;
        else s.insert({*(pt-1), i});
    }
    int pos = 0;
    set<int> ex;
    for(auto k : s) {
        int prep = 0;
        while(prep < d[k.second]) {
            if(pos == k.first) return false;
            if(!ex.count(pos)) prep++;
            pos++;
        }
        ex.insert(k.first);
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    d.resize(m + 1);
    p.resize(m + 1);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        p[t].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> d[i];
    }
    int l = -1, r = n;
    while(r > l + 1) {
        int mid = (r + l) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << (r == n ? -1 : r + 1) << "\n";
}
