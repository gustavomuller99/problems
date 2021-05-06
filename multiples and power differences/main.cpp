#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n, m; cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll> (m)), b(n, vector<ll> (m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin>>a[i][j];
    ll lcm = 720720;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if((i + j) % 2) b[i][j] = lcm;
            else b[i][j] = lcm + pow(a[i][j], 4);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << b[i][j] << " ";
        } cout << "\n";
    }
}
