#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int rec(int k, int sz, int n = 0) {
    if(t[n] <= k) return k - t[n];
    if(n >= sz && t[n]) return n;

    int a = rec(k, sz, 2*n + 2);
    if(a >= sz) return a;
    else return rec(a, sz, 2*n + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k = 1; cin >> n;
    vector<int> s(n);
    while(k<n) {k*=2;} k*=2; k--;
    t.resize(k);
    for (int i = k/2; i < k/2 + n; ++i) {
        t[i] = 1;
    }
    for (int i = k/2 - 1; i >= 0; --i) {
        t[i] = t[i*2 + 1] + t[i*2 + 2];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<int> ans;
    for (auto i = s.rbegin(); i < s.rend(); ++i) {
        int p = *i;
        int index = rec(p, k/2);
        ans.push_back(index - k/2 + 1);
        t[index] = 0;
        while(index != 0) {
            index = index/2 - (index%2 == 0);
            t[index]--;
        }
    }
    for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
        cout << *i << " ";
    } cout << "\n";
}
