#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<int> f(s.size());
    f[0] = 1; if(s.size() > 1) f[1] = 2;
    for (int i = 2; i < s.size(); ++i) f[i] = (f[i-1] + f[i-2]) % MOD;
    int b = 0, e = 0;
    unsigned long long ans = 1;
    bool p = true;
    while(b != s.size()) {
        if(s[b] == 'm' || s[b] == 'w') { p = false; break; }
        if(s[b] != 'u' && s[b] != 'n') { b++; e++; }
        else {
            char c = s[b];
            while(s[e] == c && e < s.size()) e++;
            ans = (ans * f[e-b-1]) % MOD;
            b = e;
        }
    }
    cout << (p ? ans : 0) << "\n";
}
