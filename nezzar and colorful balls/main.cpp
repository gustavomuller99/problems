#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 1, c = 1;
        for (int i = 0; i < n-1; ++i) {
            if(a[i] == a[i+1]) c++;
            else c = 1;
            ans = max(ans, c);
        }
        cout << ans << "\n";
    }
}
