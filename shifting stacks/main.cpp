#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            if(a[i] < i) { ans = false; break; }
            if(i < n-1) a[i+1] += a[i] - i;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
