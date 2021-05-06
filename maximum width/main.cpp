#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    vector<pair<int,int>> p(m);
    for (int i = 0, k = 0; i < m; ++i) {
        char c = b[i];
        while(k < n && a[k] != c) k++;
        p[i].first = k;
        k++;
    }
    for (int i = m-1, k = n-1; i >= 0; --i) {
        char c = b[i];
        while(k >= 0 && a[k] != c) k--;
        p[i].second = k;
        k--;
    }
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        ans = max(ans, p[i].second - p[i-1].first);
    }
    cout << ans;
}
