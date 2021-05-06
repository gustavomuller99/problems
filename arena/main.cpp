#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n; vector<int> a(101);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x; a[x]++;
        }
        bool f = false; int ans = 0;
        for (int i = 0; i < 101; ++i) {
            if(a[i] && !f) f = true;
            else ans += a[i];
        }
        cout << ans << "\n";
    }
}
