#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, e1 = 0, e2 = 0; cin>>n;
    vector<int> a(n+1), f(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        while(a[i] - a[e1 + 1] >= 90) e1++;
        while(a[i] - a[e2 + 1] >= 1440) e2++;
        f[i] = min(min(f[e1] + 50, f[e2] + 120), f[i-1] + 20);
        cout << f[i] - f[i-1] << "\n";
    }
}
