#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; ll u,v,ans=ULLONG_MAX; cin>>n>>u>>v;
        bool b = true;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 1; i < n; ++i) {
            if(a[i-1] < a[i] - 1 || a[i-1] > a[i] + 1) b = false;
            else if(a[i-1] == a[i]) ans = min(ans, min(2*v, u + v));
            else ans = min(ans, min(u, v));
        }
        cout << (b ? ans : 0) << "\n";
    }
}
