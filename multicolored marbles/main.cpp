#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int main() {
    int n; cin>>n;
    vector<pair<int, int>> a(n);
    a[0] = {1, 0};
    for (int i = 1; i < n; ++i) {
        if(i%2) a[i] = {a[i-1].first, (a[i-1].first + a[i-1].second + 1) % MOD};
        else a[i] = {(a[i-1].first + a[i-1].second + 1) % MOD, a[i-1].second};
    }
    cout << (a[n-1].first + a[n-1].second) % MOD;
}
