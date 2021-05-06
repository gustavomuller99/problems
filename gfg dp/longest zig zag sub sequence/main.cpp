#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        int c = a[0], ans = 1, s = 0;
        for (int i = 1; i < n; ++i) {
            if(a[i] > c && s != 1) s = 1, ans++, c = a[i];
            else if(a[i] < c && s != -1) s = -1, ans++, c = a[i];
        }
        cout << ans << "\n";
    }
}
