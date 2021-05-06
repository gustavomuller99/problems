#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        ll s = 0, e = 0, o = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s+=a[i];
            if(i%2) o+=a[i];
            else e+=a[i];
        }
        if(e <= s/2) {
            for (int i = 0; i < n; ++i) {
                if(i%2) cout << a[i] << " ";
                else cout << 1 << " ";
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if(i%2) cout << 1 << " ";
                else cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
}
