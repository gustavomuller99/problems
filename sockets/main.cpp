#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    map<ll, vector<int>> pow;
    vector<int> a(m + 1), s(m + 1), u(m + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) {
        ll p; cin >> p;
        pow[p].push_back(i);
    }
    for (int i = 1; i <= m; ++i) cin >> s[i];
    int c = 0, us = 0;
    for (int i = 0; i < 32; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(!u[j] && pow.count(s[j]) && !pow[s[j]].empty()) {
                u[j] = 1;
                us += i;
                c++;
                int cp = pow[s[j]].back();
                pow[s[j]].pop_back();
                b[cp] = j;
                a[j] = i;
            } else s[j] = (s[j] + 1) / 2;
        }
    }
    cout << c << " " << us << "\n";
    for (int i = 1; i <= m; ++i) {
        cout << a[i] << "\n";
    } cout << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << "\n";
    } cout << "\n";
}
