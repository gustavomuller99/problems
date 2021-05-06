#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string a, b; cin>>a>>b;
    ll d[a.size()][b.size()]; memset(d, 0, sizeof(d));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if(j) d[i][j] = d[i][j-1];
            if(a[i] == b[j]) d[i][j] = (d[i][j] + (i > 0 && j > 0 ? d[i-1][j-1] + 1 : 1)) % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans = (ans + d[i][b.size() - 1]) % mod;
    }
    cout << ans;
}
