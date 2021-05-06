#include <bits/stdc++.h>
using namespace std;
vector<int> a;
map<int, int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = -1, lx = 0, rx = 0, v = 0;
    while(true) {
        if(v == k) {
            if(rx - lx < r - l || l == -1) {r = rx, l = lx;}
            mp[a[lx]]--;
            if(!mp[a[lx]]) v--;
            lx++;
        } else {
            if(rx == n) break;
            if(!mp[a[rx]]) v++;
            mp[a[rx]]++;
            rx++;
        }
    }
    cout << (l == -1 ? -1 : l+1) << " " << r << "\n";
}
