#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a;
int ctl(ll q) {
    int l = -1, r = a.size(), mid = 0;
    while(r > l + 1) {
        mid = (l + r) / 2;
        if(a[mid] <= q) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
int ctr(ll q) {
    int l = -1, r = a.size(), mid = 0;
    while(r > l + 1) {
        mid = (l + r) / 2;
        if(a[mid] < q) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int lx, rx; cin >> lx >> rx;
        int r1 = ctl(lx-1); int r2 = ctr(rx+1);
        cout << r2 - r1 - 1 << "\n";
    } cout << "\n";
}
