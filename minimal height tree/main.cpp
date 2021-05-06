#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, ans=1, last=1, q=1; cin>>n; vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        queue<int> v; v.push(1);
        for (int i = 1; i < n; ++i) {
            q = v.front(); v.pop();
            while(i < n-1 && a[i] < a[i+1]) v.push(a[i]), i++;
            v.push(a[i]);
            if(q == last && i < n-1) ans++, last = a[i];
        }
        cout << ans << "\n";
    }
}
