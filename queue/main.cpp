#include <bits/stdc++.h>
using namespace std;
vector<int> r(1e6+1, -1), l(1e6+1, -1);
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        r[a] = b;
        l[b] = a;
    }
    if(n%2) { for (int i = 1; i < 1e6+1; ++i) if(l[i] > 0 && r[i] == -1) p = i; }
    else p = l[0];
    vector<int> ans(n);
    int k = r[0];
    for (int i = 1; i < n; i+=2) {
        ans[i] = k;
        k = r[k];
    }
    k = p;
    for (int i = (n%2 ? n-1 : n-2); i >= 0; i-=2) {
        ans[i] = k;
        k = l[k];
    }
    for(int x : ans) cout << x << " ";
}