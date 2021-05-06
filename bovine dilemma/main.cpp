#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        set<int> ans;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                ans.insert(a[j] - a[i]);
            }
        }
        cout << ans.size() << "\n";
    }
}
