#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t; cin>>n>>t;
    vector<int> a(n-1),p(n);
    for (int i = 0; i < n-1; ++i) cin>>a[i];
    stack<int> s; s.push(0);
    p[0] = 1;
    while(!s.empty()) {
        int r = s.top(); s.pop();
        if(r < n-1 && p[r+a[r]]==0) p[r+a[r]] = 1, s.push(r + a[r]);
    }
    cout << (p[t-1] == 0 ? "NO" : "YES");
}
