#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nb, ns, nc, pb, ps, pc, b, s, c;
ll r;
bool f(ll x) {
    return max(0LL, b*x - nb)*pb + max(0LL, s*x - ns)*ps + max(0LL, c*x - nc)*pc <= r;
}
int main() {
    string in;
    cin >> in >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    for (char i : in) {
        if(i == 'B') b++;
        else if (i == 'S') s++;
        else c++;
    }
    ll lo = 0, hi = 1;
    while(f(hi)) hi *= 2;
    while(hi > lo + 1) {
        ll mid = (lo + hi) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
}

