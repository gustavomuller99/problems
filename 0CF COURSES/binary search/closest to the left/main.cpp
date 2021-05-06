#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        int q; cin >> q;
        int l = -1, r = n, mid = 0;
        while(r > l + 1) {
            mid = (l + r) / 2;
            if(a[mid] <= q) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l+1 << '\n';
    }
}
