#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> m(k);
    for (int i = 0; i < n; ++i) { int t; cin >> t; m[t-1]++; }
    sort(m.begin(), m.end(), greater<>());
    unsigned long long mn = INT_MAX;
    for (int i = (k+1)/2; i <= k; ++i) {
        int sz = 0;
        int s = (i - (k+1)/2)*2 + k%2;
        vector<int> c = m;
        auto j = c.begin();
        while(j < c.end()) {
            if(s) {
                s--;
                sz = max(sz, *j);
            } else {
                sz = max(sz, *j + c[c.size()-1]);
                c.pop_back();
            }
            j++;
        }
        mn = min(mn, (unsigned long long) i*sz);
    }
    cout << mn << "\n";
}
