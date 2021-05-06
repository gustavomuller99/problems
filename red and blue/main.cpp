#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, m, sum = 0, mx = 0, ans = 0; cin>>n;
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            cin>>r[i];
            sum += r[i];
            if(sum > mx) mx = sum;
        }
        ans += mx;
        cin>>m;
        vector<int> b(m);
        sum = 0, mx = 0;
        for (int i = 0; i < m; ++i) {
            cin>>b[i];
            sum += b[i];
            if(sum > mx) mx = sum;
        }
        ans += mx;
        cout << ans << "\n";
    }
}
