#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, k;
bool f(int x) {
    vector<int> c = a, p(n);
    int m = 0;
    bool ans = false;
    for (int i = 0; i < n; ++i) c[i] = (c[i] >= x ? 1 : -1);
    for (int i = 0; i < n; ++i) {
        p[i] = c[i] + (i > 0 ? p[i-1] : 0);
        if(i > k-1) m = min(m, p[i-k]);
        if(i >= k-1) ans = ans | (p[i] - m > 0);
    }
    return ans;
}
int main() {
    cin>>n>>k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    int l = 1, r = n+1;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}
