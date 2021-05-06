#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> s;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    s.resize((1 << (n + 1)) - 1);
    for(int i = (1 << n)-1; i < (1 << n+1) - 1; ++i) {
        cin >> s[i];
    }
    bool op = true; int k = n-1;
    while(k >= 0) {
        for(int i = (1 << k)-1; i < (1 << k+1)-1; ++i) {
            if(op) s[i] = s[2*i + 1] | s[2*i + 2];
            else s[i] = s[2*i + 1] ^ s[2*i + 2];
        }
        op = !op;
        k--;
    }
    while(m--) {
        int p; ll b; cin >> p >> b; p--;
        p = s.size()/2 + p;
        s[p] = b; bool op = true;
        while(p != 0) {
            p = p/2 - (p % 2 == 0);
            if(op) s[p] = s[2*p + 1] | s[2*p + 2];
            else s[p] = s[2*p + 1] ^ s[2*p + 2];
            op = !op;
        }
        cout << s[0] << "\n";
    }
}
