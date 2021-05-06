#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, xc; cin >> n >> k;
    xc = k / 2 + k % 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int c[k + 1][k + 1], u[k + 1][k + 1];
    memset(c, 0, sizeof(c)); memset(u, 0, sizeof(u));
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) c[i][j] = abs(i - xc) + abs(j - xc) + c[i][j - 1];
    }
    for (int i = 0; i < n; ++i) {
        int ans = INT_MAX;
        int r, tl, td;
        for (int j = 1; j <= k; ++j) {
            int b = 1;
            for (int e = 1; e <= k; ++e) {
                if(u[j][e]) { b = e + 1; continue; }
                if(e - b + 1 == a[i]) {
                    if(ans > c[j][e] - c[j][b-1]) {
                        ans = c[j][e] - c[j][b-1];
                        r = j;
                        tl = b; td = e;
                    }
                    b++;
                }
            }
        }
        if(ans == INT_MAX) cout << -1 << "\n";
        else {
            for (int j = tl; j <= td; ++j) u[r][j] = 1;
            cout << r << " " << tl << " " << td << "\n";
        }
    }
}
