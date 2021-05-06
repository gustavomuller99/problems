#include <bits/stdc++.h>
using namespace std;
int cb(int n, int m) {
    int s = n - m;
    int r1 = 1, r2 = 1;
    for (int i = n; i > s; --i) r1 *= n, n--;
    for (int i = m; i > 0; --i) r2 *= m, m--;
    return r1 / r2;
}
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int k; cin>>k;
    vector<int> c;
    int l = 2, r = 101;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        if(cb(mid, 3) > k) r = mid;
        else l = mid;
    }
    c.resize(l, l-1);
    int sum = cb(l, 3);
    while(sum != k) {
        l = 1, r = c.size();
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(cb(mid, 2) > k - sum) r = mid;
            else l = mid;
        }
        sum += cb(l, 2);
        for (int i = 0; i < l; ++i) c[i]++;
        c.push_back(l);
    }
    int m[c.size()][c.size()];
    for (int i = 0; i < c.size(); ++i) {
        m[i][i] = 0;
        for (int j = 0; j < i; ++j) {
            if(c[i] && c[j]) {
                c[i]--; c[j]--;
                m[i][j] = 1;
            } else m[i][j] = 0;
        }
    }
    for (int i = 0; i < c.size(); ++i) {
        for (int j = i+1; j < c.size(); ++j) {
            m[i][j] = m[j][i];
        }
    }
    cout << c.size() << "\n";
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < c.size(); ++j) {
            cout << m[i][j];
        } cout << "\n";
    }
}
