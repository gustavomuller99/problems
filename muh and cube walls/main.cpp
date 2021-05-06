#include <bits/stdc++.h>
using namespace std;
vector<int> pi;
int n,w;
vector<int> a,b;
void c() {
    int q = -1;
    pi[0] = -1;
    for (int i = 1; i < w - 1; ++i) {
        while (q > -1 && b[q + 1] != b[i]) q = pi[q];
        if (b[q + 1] == b[i]) q++;
        pi[i] = q;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>w;
    if(w==1) cout << n;
    else {
        a.resize(n);
        b.resize(w);
        pi.resize(w);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n - 1; ++i) a[i] = a[i] - a[i + 1];
        for (int i = 0; i < w; ++i) cin >> b[i];
        for (int i = 0; i < w - 1; ++i) b[i] = b[i] - b[i + 1];
        c();
        int ans = 0, q = -1;
        for (int i = 0; i < n - 1; ++i) {
            while (q > -1 && b[q + 1] != a[i]) q = pi[q];
            if (b[q + 1] == a[i]) q++;
            if (q + 2 == b.size()) ans++, q = pi[q];
        }
        cout << ans;
    }
}
