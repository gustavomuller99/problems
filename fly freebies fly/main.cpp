#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int p;
int main() {
    int n; cin >> n;
    t.resize(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end());
    cin >> p;
    int k = 1;
    for (int i = 0; i < n; ++i) {
        int it = upper_bound(t.begin(), t.end(), t[i]+p) - t.begin();
        k = max(k, it-i);
    }
    cout << k << "\n";
}
