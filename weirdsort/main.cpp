#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> p(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            int k;
            cin >> k;
            p[k-1] = 1;
        }
        int c, d;
        for (int l = 0; l < n-1; ++l) {
            if(p[l]) {
                c = l; d = l;
                for(int i = d+1; i < n-1; ++i) {
                    if(p[i]) d++;
                    else break;
                }
                sort(&a[c], &a[d+2]);
                l = d+1;
            }
        }

        bool s = true;
        for (int j = 0; j < n-1; ++j) {
            s &= a[j] <= a[j+1];
        }
        if(s) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
