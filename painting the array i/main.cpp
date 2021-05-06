#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int l = -1, r = -1, ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        if(a[i] == l && a[i] == r);
        else if(a[i] == l && a[i] != r) r = a[i], ans++;
        else if(a[i] == r && a[i] != l) l = a[i], ans++;
        else if(i < n-1 && a[i + 1] == l) l = a[i], ans++;
        else r = a[i], ans++;
    }
    cout << ans << "\n";
}
