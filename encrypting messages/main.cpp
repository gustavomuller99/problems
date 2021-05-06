#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, c; cin >> n >> m >> c;
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        p[i] += k;
        p[i+1] -=k;
    }
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        p[i] += k;
        p[n-m+i+1] -= k;
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += p[i];
        cout << s % c << " ";
    }
}
