#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int n,k,d=2;cin>>n>>k;
    t.resize(n+1);
    vector<int> l(k);
    for (int i = 2; i <= k+1; ++i) l[i-2] = i, t[1].push_back(i);
    for (int i = k+2; i <= n; ++i) {
        t[l[(i-2)%k]].push_back(i);
        l[(i-2)%k] = i;
        if((i-2)%k == 0 || (i-2)%k == 1) d++;
    }
    cout << d << "\n";
    for (int i = 1; i <= n; ++i) for (int j = 0; j < t[i].size(); ++j) cout << i << " " << t[i][j] << "\n";
}
