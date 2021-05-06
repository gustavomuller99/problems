#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        set<int> p;
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            ll q; cin >> q;
            if(q != 0) {
                while(q > 0 && ans) {
                    if (q % k == 0) {
                        int po = 0;
                        while (pow(k, po) <= q) po++;
                        po--;
                        q -= pow(k, po);
                        ans &= !p.count(po);
                        p.insert(po);
                    } else {
                        q -= 1;
                        ans &= !p.count(0);
                        p.insert(0);
                    }
                }
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
}
