#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    vector<int> ca, cb, ans;
    int h = 0;
    while(a) { ca.push_back(a % 10); a /= 10; }
    while(b) { cb.push_back(b % 10); b /= 10; }
    for(int k : ca) h = max(h, k);
    for(int k : cb) h = max(h, k);
    h++;
    int r = 0;
    for (int i = 0; i < max(ca.size(), cb.size()); ++i) {
        int na = (i < ca.size() ? ca[i] : 0);
        int nb = (i < cb.size() ? cb[i] : 0);
        int s = (na + nb + r) % h;
        r = (na + nb + r) / h;
        ans.push_back(s);
    }
    if(r) ans.push_back(r);
    cout << ans.size();
}
