#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0; cin>>n;
    vector<pair<int, pair<int, int>>> r(n);
    vector<pair<int,int>> p;
    multiset<int> t;
    map<int, queue<int>> m;
    for (int i = 0; i < n; ++i) cin>>r[i].second.first>>r[i].first, r[i].second.second = i+1;
    cin>>k;
    for (int i = 0; i < k; ++i) {
        int x; cin>>x; t.insert(x); m[x].push(i+1);
    }
    sort(r.begin(), r.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        int c = r[i].first, a = r[i].second.first, index = r[i].second.second;
        auto it = t.lower_bound(a);
        if(it != t.end()) {
            ans += c;
            p.push_back({index, m[*it].front()});
            m[*it].pop();
            t.erase(it);
        }
    }
    cout << p.size() << " " << ans << "\n";
    for(auto pp : p) cout << pp.first << " " << pp.second << "\n";
}
