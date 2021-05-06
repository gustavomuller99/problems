#include <bits/stdc++.h>
using namespace std;
vector<int> d, a;
void dfs(int i, int j, int dth = 0) {
    if(j < i) return;
    int mx = 0, in = 0;
    for (int k = i; k <= j; ++k) {
        if(a[k] > mx) mx = a[k], in = k;
    }
    d[in] = dth;
    if(i == j) return;
    dfs(i,in-1,dth+1);
    dfs(in+1,j,dth+1);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        d = a = vector<int> (n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        dfs(0,n-1);
        for (int i = 0; i < n; ++i) cout << d[i] << " ";
        cout << "\n";
    }
}
