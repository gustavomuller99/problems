#include <bits/stdc++.h>
using namespace std;
int n, m;
unsigned long long k;
vector<int> cnt(const vector<int>& a) {
    vector<int> sz(a.size()+1);
    int i = 0;
    while(i < a.size()) {
        if(a[i] == 0) {
            i++;
            continue;
        }
        int j = i;
        while(j < a.size() && a[j] == 1) j++;
        for (int len = 0; len < j - i; ++len) {
            sz[len+1] += j - i - len;
        }
        i = j;
    }
    return sz;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector<int> sza = cnt(a);
    vector<int> szb = cnt(b);
    unsigned long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if(k % i == 0 && k/i <= m) ans += sza[i] * szb[k/i];
    }
    cout << ans << "\n";
}
