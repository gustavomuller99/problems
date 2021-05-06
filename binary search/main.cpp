    #include <bits/stdc++.h>
    using namespace std;
    vector<int> a;
    #define ll long long
    ll MOD = 1e9 + 7;
    int main() {
        int n, x, pos; cin>>n>>x>>pos;
        int k = n;
        a.resize(n);
        a[pos] = 1;
        int lower = x - 1, higher = n - x;
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(mid == pos) {
                l = mid + 1;
            }
            else if(mid < pos) {
                l = mid + 1;
                a[mid] = lower;
                lower--;
            }
            else {
                r = mid;
                a[mid] = higher;
                higher--;
            }
            k--;
        }
        for (int i = 0; i < n; ++i) if(!a[i]) a[i] = k, k--;
        ll ans = 1;
        for (int i = 0; i < n; ++i) ans *= a[i], ans %= MOD;
        cout << ans;
    }