#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string ans;
        for (int i = 0; i < n; ++i) ans.push_back('a');
        int p1 = n - 1, p2 = n;
        int p = 1;
        while(p < k) {
            p1--;
            p += n - p1;
        }
        p2 = p - k;
        ans[p1-1] = 'b';
        ans[p1+p2] = 'b';
        cout << ans << endl;
    }
}
