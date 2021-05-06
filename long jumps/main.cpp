#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n), d(n+1);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) {
            d[min(n, a[i] + i)] = max(d[min(n, a[i] + i)], d[i] + a[i]);
        }
        cout << d[n] << "\n";
    }
}
