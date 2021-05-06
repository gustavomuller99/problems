#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n, k, ans = 0; cin>>n>>k;
    vector<int> a(26);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    string in; cin>>in;
    for (int i = 0; i < k; ++i) {
        char c; cin>>c; a[c-'a']=1;
    }
    for (ll i = 0; i < n; ++i) {
        if(!a[in[i]-'a']) continue;
        if(i < n-1) d[i+1] = d[i];
        ans += (i-d[i]+1);
    }
    cout << ans;
}
