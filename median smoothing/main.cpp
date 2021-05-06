#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, ans = 0; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        int l = i;
        while(l < n-1 && a[l+1] == a[l]) l++;
        int r = l;
        while(r < n-1 && a[r+1] != a[r]) r++;
        if(r - l > 1) ans = max(ans,(r-l)/2);
        if(a[l] == a[r]) for (int j = l; j < r; ++j) a[j] = a[l];
        else {
            for (int j = l; j <= (r + l) / 2; ++j) a[j] = a[l];
            for (int j = (r + l) / 2 + 1; j < r; ++j) a[j] = a[r];
        }
        i = r;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
