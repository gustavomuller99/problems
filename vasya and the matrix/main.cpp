#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, xa=0, xb=0; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin>>a[i], xa ^= a[i];
    for(int i = 0; i < m; ++i) cin>>b[i], xb ^= b[i];
    if(xa != xb) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int e00 = a[0];
        for (int i = 1; i < m; ++i) e00 ^= b[i];
        cout << e00 << " ";
        for (int i = 1; i < m; ++i) cout << b[i] << " ";
        cout << "\n";
        b = vector<int> (m);
        for (int i = 1; i < n; ++i) {
            b[0] = a[i];
            for (int j = 0; j < m; ++j) cout << b[j] << " ";
            cout << "\n";
        }
    }
}
