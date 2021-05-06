#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll k; cin >> k;
        vector<int> a(7);
        int s = 0;
        for (int i = 0; i < 7; ++i) { cin >> a[i]; s += a[i]; }
        ll ans = (k / s - (k % s ? 0 : 1)) * 7, r = ULLONG_MAX;
        for (int i = 0; i < 7; ++i) {
            int p = (k % s == 0 ? s : k % s);
            int d = 0, j = i;
            while(p) {
                p -= a[j%7];
                d++;
                j++;
            }
            r = min(r, ans + d);
        }
        cout << r << "\n";
    }
}
