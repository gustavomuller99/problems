#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int rec(int l, int r, int lx, int rx, int n = 0) {
    if(lx > l && rx < r) return t[n];
    if(rx <= l || lx >= r) return 0;

    int mid = (lx + rx) / 2;
    return rec(l, r, lx, mid, 2*n + 1) + rec(l, r, mid + 1, rx, 2*n + 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k = 1;
    cin >> n;
    vector<int> s(2 * n);
    vector<int> sum(n);
    vector<int> m(n, -1);
    while (k < 2 * n) k *= 2;
    k *= 2;
    k--;
    t.resize(k);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> s[i];
    }
    for (int j = 0; j < 2; ++j) {
        for (auto i = 0; i < 2*n; ++i) {
            int p = s[i] - 1;
            if(m[p] == -1) {
                m[p] = i;
                int index = k/2 + m[p];
                t[index]++;
                while(index != 0) {
                    index = index/2 - (index%2 == 0);
                    t[index]++;
                }
            } else {
                int r = rec(m[p], i, 0, k/2);
                int index = k/2 + m[p];
                t[index]--;
                while(index != 0) {
                    index = index/2 - (index%2 == 0);
                    t[index]--;
                }
                sum[p] += r;
            }
        }
        t = vector<int> (k, 0);
        m = vector<int> (n, -1);
        reverse(s.begin(), s.end());
    }
    for(int u : sum) {
        cout << u << " ";
    } cout << "\n";
}
