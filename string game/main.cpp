#include <bits/stdc++.h>
using namespace std;
string t, p;
bool f(string c) {
    int k = 0;
    for (int i = 0; i < c.size(); ++i) {
        if(c[i] == p[k]) k++;
        if(k == p.size()) break;
    }
    return k == p.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> p;
    vector<int> a(t.size());
    for (int i = 0; i < t.size(); ++i) {
        cin >> a[i];
    }
    int l = -1, r = t.size();
    while(r > l + 1) {
        int mid = (l + r) / 2;
        string c = t;
        for (int i = 0; i < mid; ++i) c[a[i] - 1] = -1;
        if(f(c)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}

