#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;cin>>t;while(t--) {
        int n; cin>>n; vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        sort(a.begin(), a.end());
        unsigned long long ans = 0, l = 0;
        for (unsigned long long i = 0; i < n; ++i) {
            while(a[i] - a[l] > 2) l++;
            ans += ((i-l)*(i-l-1))/2;
        }
        cout << ans << "\n";
    }
}
