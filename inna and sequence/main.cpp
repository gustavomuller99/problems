#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int rec(int k, int sz, int n = 0) {
    if(t[n] <= k) return k - t[n];
    if(n >= sz && t[n]) return n;
    int a = rec(k, sz, 2*n+1);

    if(a >= sz) return a;
    else return rec(a, sz, 2*n+2);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, q1 = 0, q2 = 0, k = 1; cin>>n>>m;
    vector<int> a(m), el;
    for (int i = 0; i < m; ++i) cin>>a[i];
    while(k < n) k *= 2; k *= 2; k--;
    t.resize(k);
    for (int i = 0; i < n; ++i) {
        int p; cin>>p;
        if(p == 0 || p == 1) {
            el.push_back(p);
            int index = k/2 + q1;
            t[index] = 1;
            while(index != 0) {
                index = index/2 - (index%2==0);
                t[index] = t[2*index+1] + t[2*index+2];
            }
            q1++; q2++;
        } else {
            vector<int> rm;
            int l = -1, r = m;
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if(a[mid] > q2) r = mid;
                else l = mid;
            }
            q2 -= l+1;
            for (int j = 0; j <= l; ++j) rm.push_back(rec(a[j]-1, k/2));
            for (int x : rm) {
                t[x] = 0;
                while(x != 0) {
                    x = x/2 - (x%2==0);
                    t[x] = t[2*x+1] + t[2*x+2];
                }
            }
        }
    }
    bool empty = true;
    for (int i = 0; i < el.size(); ++i) if(t[k/2 + i]) empty = false, cout << el[i];
    if(empty) cout << "Poor stack!";
}
