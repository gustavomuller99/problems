#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> v;
vector<ll> a, p;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    p.push_back(a[0]);
    v.emplace_back(); v[0].push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        int l = -1, r = p.size();
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(p[mid] > a[i]) l = mid;
            else r = mid;
        }
        if(r == p.size()) {
            p.push_back(a[i]);
            v.emplace_back(); v[p.size() - 1].push_back(a[i]);
        } else {
            p[r] = a[i];
            v[r].push_back(a[i]);
        }
    }
    for(const auto& x : v) {
        for(int y : x) cout << y << " ";
        cout << "\n";
    }
}
