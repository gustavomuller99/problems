#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> g(n);
        for (int i = 0; i < n; ++i) {
            cin >> g[i];
        }
        bool ans = true;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if(g[i][j]=='1') {
                    if(g[i][j+1] == '0' && g[i+1][j] == '0') ans = false;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}
