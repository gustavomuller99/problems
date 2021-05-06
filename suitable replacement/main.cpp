#include <bits/stdc++.h>
using namespace std;
vector<int> s(26);
vector<int> t(26);
vector<int> q;
bool f(int x) {
    bool ans = true;
    int c = q.size();
    for (int i = 0; i < 26; ++i) {
        ans &= t[i]*x - s[i] <= c;
        c -= max(0, t[i]*x - s[i]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b; cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] == '?') q.push_back(i);
        else s[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); ++i) {
        t[b[i] - 'a']++;
    }
    int l = 0, r = 1;
    while(f(r)) r *= 2;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    string ans = a;
    for (int i = 0; i < 26; ++i) {
        t[i] = t[i]*l - s[i];
    }
    int k = 0;
    for (int i = 0; i < 26;) {
        if(k == q.size()) break;
        while(t[i] <= 0 && i < 25) i++;
        ans[q[k]] = i + 'a';
        t[i]--;
        k++;
    }
    cout << ans << "\n";
}
