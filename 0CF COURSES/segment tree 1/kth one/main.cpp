#include <bits/stdc++.h>
using namespace std;
vector<int> t(1e6, 0);
int rec(int k, int sz, int n = 0) {
    if(t[n] <= k) return k - t[n];
    if(n >= sz && t[n]) return n;

    int a = rec(k, sz, 2*n + 1);
    if(a >= sz) return a;
    else return rec(a, sz,2*n + 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k<n) {k*=2;} k*=2; k--;
    for (int i = k/2; i < k/2 + n; ++i) {
        cin >> t[i];
    }
    for (int i = k/2 - 1; i >= 0; --i) {
        t[i] = t[i*2 + 1] + t[i*2 + 2];
    }
    while(m--) {
        int o, i; cin >> o >> i;
        if(o == 2) {
            cout << rec(i, k/2) - k/2 << endl;
        } else {
            i = k/2 + i;
            int d = !t[i] - t[i];
            t[i] = !t[i];
            while(i != 0) {
                i = i/2 - (i%2 == 0);
                t[i] = t[i] + d;
            }
        }
    }
}
