#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int rec(int l, int r, int lx, int rx, int n = 0) {
    if(lx >= l && rx <= r) return t[n];
    if(rx < l || lx > r) return 0;

    int mid = (lx + rx) / 2;
    return rec(l, r, lx, mid, 2*n + 1) + rec(l, r, mid+1, rx, 2*n + 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k = 1; cin >> n;
    vector<int> s(n);

    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back(rec(s[i] - 1, k/2, 0, k/2));
        int index = k/2 + s[i] - 1;
        t[index]++;
        while(index != 0) {
            index = index/2 - (index%2 == 0);
            t[index]++;
        }
    }
    for(int u : ans) {
        cout << u << " ";
    } cout << "\n";
}
