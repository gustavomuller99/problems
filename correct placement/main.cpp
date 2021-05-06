#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<pair<pair<ll, ll>, pair<pair<int,int>, ll>>> a(n);
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) cin>>a[i].first.first>>a[i].first.second, a[i].second.first.first = i;
        sort(a.begin(), a.end());
        int m = INT_MAX, in = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i].first.second < m) m = a[i].first.second, in = a[i].second.first.first;
            a[i].second.first.second = in;
            a[i].second.second = m;
        }
        for (int i = 0; i < n; ++i) {
            int h = a[i].first.first, w = a[i].first.second;
            int l = -1, r = n;
            while(l + 1 < r) {
                int mid = (l+r)/2;
                if(a[mid].first.first >= h) r = mid;
                else l = mid;
            }
            if(l > -1 && a[l].second.second < w) { ans[a[i].second.first.first] = a[l].second.first.second+1; continue; }
            l = -1, r = n;
            while(l + 1 < r) {
                int mid = (l+r)/2;
                if(a[mid].first.first >= w) r = mid;
                else l = mid;
            }
            if(l > -1 && a[l].second.second < h) ans[a[i].second.first.first] = a[l].second.first.second + 1;
        }
        for(int x : ans) cout << x << " "; cout << "\n";
    }
}
