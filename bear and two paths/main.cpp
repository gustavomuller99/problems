#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int n, m, a, b, c, d; cin >> n >> m >> a >> b >> c >> d;
    if(m < n + 1 || n < 5) cout << -1 << "\n";
    else {
        int mid;
        for (int i = 1; i <= n; ++i) if(i != a && i != b && i != c && i != d) { mid = i; break; }
        cout << a << " " << d << " " << mid << " " << c << " ";
        for (int i = 1; i <= n; ++i) if(i != a && i != b && i != c && i != d && i != mid) cout << i << " ";
        cout << b << "\n";
        cout << c << " ";
        for (int i = 1; i <= n; ++i) if(i != a && i != b && i != c && i != d && i != mid) cout << i << " ";
        cout << b << " " << mid << " " << a << " " << d << "\n";
    }
}
