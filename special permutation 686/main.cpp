#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        for (int i = 1; i <= n; ++i) cout << i%n + 1 << " ";
        cout << "\n";
    }
}
