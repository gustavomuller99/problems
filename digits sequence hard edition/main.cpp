#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll k,ac=0,m=9,i,pw;
bool f(ll x) {
    return (x - pw) * i < k;
}
int main() {
    cin>>k;
    for (i = 1; ac < k; i++) {
        ac += i*m;
        m *= 10;
    } i--; m /= 10; ac -= i*m; k-= ac;
    pw = pow(10, i-1); ll l = pw, r = pw*10;
    while(l + 1 < r) {
        ll mid = (l + r)/2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    k = k - (l - pw) * i;
    int index = i - k + 1;
    for(int j = 1; j < index; j++) l /= 10;
    cout << l%10;
}
