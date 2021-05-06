#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(n), h(n+1), ans;
        for (int i = 0; i < n; ++i) cin>>a[i];
        int s = n;
        for (int i = n-1; i >= 0; --i) {
            while(h[s]) s--;
            int l = i;
            h[s] = 1;
            while(i >= 0 && a[i] != s) h[a[i]] = 1, i--;
            for (int j = i; j <= l; ++j) ans.push_back(a[j]);
        }
        for(int k : ans) cout << k << " "; cout << "\n";
    }
}
