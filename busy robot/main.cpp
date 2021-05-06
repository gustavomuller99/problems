#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<pair<ll, ll>> a(n);
        vector<pair<bool, pair<int, ll>>> b(n);
        for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second;
        b[0].first = true;
        b[0].second.first = (a[0].second > 0 ? 1 : -1), b[0].second.second = 0;
        ll time = a[0].first + abs(a[0].second), pos = a[0].second;
        for (int i = 1; i < n; ++i) {
            if(a[i].first >= time) {
                b[i].first = true;
                b[i].second.second = pos;
                b[i].second.first = (pos > a[i].second ? -1 : 1);
                time = a[i].first + abs(pos-a[i].second);
                pos = a[i].second;
            } else {
                b[i].first = false;
                b[i].second.second = (b[i-1].second.first == 1 ? b[i-1].second.second + (a[i].first - a[i-1].first) : b[i-1].second.second - (a[i].first - a[i-1].first));
                b[i].second.first = b[i-1].second.first;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(b[i].first) {
                pos = a[i].second;
                if(i == n-1 || b[i+1].first) ans++;
            } else {
                if(b[i].second.first == 1 && b[i].second.second <= a[i].second && a[i].second <= pos) {
                    if(i == n-1) ans++;
                    else if(b[i].second.second + (a[i+1].first - a[i].first) >= a[i].second) ans++;
                }
                if(b[i].second.first == -1 && b[i].second.second >= a[i].second && a[i].second >= pos) {
                    if(i == n-1) ans++;
                    else if(b[i].second.second - (a[i+1].first - a[i].first) <= a[i].second) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
