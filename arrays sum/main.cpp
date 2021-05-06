#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, k, d = 1; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(i && a[i] != a[i-1]) d++;
        }
        if(k > 1) {
            d = max(0, d - k);
            cout << ceil((float) d / (float) (k-1)) + 1 << "\n";
        }
        else if(d == 1) cout << 1 << "\n";
        else cout << -1 << endl;
    }
}
