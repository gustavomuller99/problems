#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<int> a(1001);
    bool p = true, pc;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n*n; ++i) {
        int x; cin>>x; a[x]++;
    }
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            pc = false;
            for (int k = 0; k < 1001; ++k) {
                if(a[k] >= 4) {
                    pc = true, a[k] -= 4;
                    ans[i][j] = k;
                    ans[i][n-j-1] = k;
                    ans[n-i-1][j] = k;
                    ans[n-i-1][n-j-1] = k;
                    break;
                }
            }
            p &= pc;
        }
    }
    if(n%2) {
        for (int i = 0; i < n/2; ++i) {
            pc = false;
            for (int k = 0; k < 1001; ++k) {
                if(a[k] >= 2) {
                    pc = true;
                    a[k] -= 2;
                    ans[i][n/2] = k;
                    ans[n-i-1][n/2] = k;
                    break;
                }
            }
            p &= pc;
        }
        for (int j = 0; j < n/2; ++j) {
            pc = false;
            for (int k = 0; k < 1001; ++k) {
                if(a[k] >= 2) {
                    pc = true;
                    a[k] -= 2;
                    ans[n/2][j] = k;
                    ans[n/2][n-j-1] = k;
                    break;
                }
            }
            p &= pc;
        }
        pc = false;
        for (int k = 0; k < 1001; ++k) {
            if(a[k]) {
                pc = true;
                ans[n/2][n/2] = k;
            }
        }
        p &= pc;
    }
    if(p) {
        cout << "YES\n";
        for(const auto& x : ans) {
            for(auto y : x) cout << y << " "; cout << "\n";
        }
    } else cout << "NO";
}
