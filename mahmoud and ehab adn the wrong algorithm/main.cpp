#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int n; cin >> n;
    if(n <= 5) cout << -1 << "\n";
    else {
        for (int i = 2; i <= n/2 + 1; ++i) cout << 1 << " " << i << "\n";
        for (int i = n/2 + 2; i <= n; ++i) cout << 2 << " " << i << "\n";
    }
    for (int i = 1; i <= n-1; ++i) cout << i << " " << i+1 << "\n";
}
