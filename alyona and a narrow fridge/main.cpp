#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a;
ll h;
bool f(int x) {
    vector<int> c(x);
    for (int i = 0; i < x; ++i) {
        c[i] = a[i];
    } sort(c.begin(), c.end(), greater<>());
    ll sum = 0;
    for (int i = 0; i < x; i+=2) {
        sum += c[i];
    }
    return sum <= h;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n >> h;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n+1;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}
