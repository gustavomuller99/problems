#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        bool ans = true;
        int a[n][n], b[n][n];
        vector<int> c(n), r(n);
        for (int i = 0; i < n; ++i) {
            string in; cin>>in;
            for (int j = 0; j < n; ++j) {
                a[i][j] = in[j] - '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            string in; cin>>in;
            for (int j = 0; j < n; ++j) {
                b[i][j] = in[j] - '0';
            }
        }
        for (int i = 0; i < n; ++i) if(a[0][i] != b[0][i]) c[i]++;
        for (int i = 1; i < n; ++i) if((c[0] == 0 && a[i][0] != b[i][0]) || (c[0] == 1 && a[i][0] == b[i][0])) r[i]++;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if((r[i] + c[j]) % 2 && a[i][j] == b[i][j]) ans = false;
                if((r[i] + c[j]) % 2 == 0 && a[i][j] != b[i][j]) ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
