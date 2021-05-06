#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> d;
vector<ll> a;
int n;
ll rec(int l, int r) {
    if(r == l) return 0;
    if(d[l][r] != -1) return d[l][r];
    d[l][r] = a[r] - a[l] + min(rec(l+1,r), rec(l,r-1));
    return d[l][r];
}
int main() {
    cin>>n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    sort(a.begin(), a.end());
    d.resize(n, vector<ll>(n, -1));
    cout << rec(0,n-1);
}
