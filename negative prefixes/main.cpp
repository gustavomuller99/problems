#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), l(n), v;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            if(l[i] == 0) v.push_back(a[i]);
        }
        sort(v.begin(), v.end(), greater<>());
        int k = 0;
        for (int i = 0; i < n; ++i) if(l[i] == 0) { a[i] = v[k]; k++; }
        for(int x : a) {
            cout << x << " ";
        } cout << "\n";
    }
}
