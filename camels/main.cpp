#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin>>n>>t;
    int d[n][2*t][4]; memset(d, 0, sizeof(d));
    for (int i = 0; i < 4; ++i) d[0][0][i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 2*t-1; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    if(k == l) continue;
                    if(j % 2 == 0) {
                        if(l > k) d[i][j][l] += d[i-1][j][k];
                        if(l < k) d[i][j+1][l] += d[i-1][j][k];
                    } else {
                        if(l < k) d[i][j][l] += d[i-1][j][k];
                        if(l > k) d[i][j+1][l] += d[i-1][j][k];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) ans += d[n-1][2*t-1][i];
    cout << ans;
}
