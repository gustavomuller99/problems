#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, ans = 0; cin>>n;
        vector<int> c(3);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x; c[x%3]++;
        }
        n = n/3;
        for (int i = 0; i < 3; ++i) {
            int k = -1;
            for (int j = 0; j < 3; ++j) if(c[j] > n) k = j;
            if(k == -1) break;
            c[(k+1)%3] += (c[k] - n);
            ans += (c[k] - n);
            c[k] = n;
        }
        cout << ans << "\n";
    }
}
