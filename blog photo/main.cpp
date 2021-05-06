#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
double f(double x, double y) { return x/y; }
int main() {
    ll h,w,ha=0,wa=0; cin>>h>>w;
    for(ll a = 1; a <= w; a = a << 1) {
        ll l = 1, r = h+1;
        while(l + 1 < r) {
            ll mid = (l + r)/2;
            if(f(mid,a) - 1.25 < 10e-256) l = mid;
            else r = mid;
        }
        if((f(l,a) - 0.8 > 10e-6 || fabs(f(l,a) - 0.8) < 10e-256) && f(l,a) - 1.25 < 10e-256 && l > ha && ha*wa <= l*a) ha = l, wa = a;
        if(wa > ha && wa <= h) swap(wa, ha);
    }
    cout << ha << " " << wa;
}