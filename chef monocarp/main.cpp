#include <bits/stdc++.h>
using namespace std;
#define long long int
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n), d(n, 1e9);
        for (int i = 0; i < n; ++i) cin>>a[i];
        sort(a.begin(), a.end());
        for (int i = 1; i <= 1e5; ++i) {
            for (int j = n-1; j >= 0; --j) {
                d[j] = min(d[j], (j > 0 ? d[j-1] : 0) + abs(a[j] - i));
            }
        }
        cout << d[n-1] << "\n";
    }
}
