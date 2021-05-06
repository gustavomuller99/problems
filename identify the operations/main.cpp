#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 998244353
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,k;cin>>n>>k;
        ll ans = 1;
        vector<int> a(n), b(k), c(n);
        map<int,int> mp;
        for (int i = 0; i < n; ++i) cin>>a[i], a[i]--, mp[a[i]] = i;
        for (int i = 0; i < k; ++i) cin>>b[i], b[i]--, c[b[i]]=1;
        for (int i = 0; i < k; ++i) {
            int index = mp[b[i]], m = 2;
            c[b[i]] = 0;
            if((index && c[a[index - 1]]) || index == 0) m--;
            if((index < n-1 && c[a[index + 1]]) || index == n-1) m--;
            ans = (ans * m)%MOD;
        }
        cout << ans << "\n";
    }
}
