    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    vector<pair<ll, ll>> a;
    int main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int n; ll d;
        cin>>n>>d;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second;
        sort(a.begin(), a.end());
        int b=0, e=0;
        ll sum=0, mx=0;
        while(e!=n) {
            if(a[e].first - a[b].first >= d) {
                sum-=a[b].second;
                b++;
            } else {
                sum+=a[e].second;
                e++;
                mx = max(sum, mx);
            }
        }
        cout<<mx;
    }