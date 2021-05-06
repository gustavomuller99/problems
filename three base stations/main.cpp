#include <bits/stdc++.h>
using namespace std;
vector<double> a;
bool f(double d) {
    int b = 0, v = 0;
    for (int i = 0; i < a.size(); ++i) {
        if((a[i]-a[b])/2 > d) {
            v++;
            b = i;
        }
    }
    return v+1 <= 3;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;cin>>n;a.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    sort(a.begin(), a.end());
    double l = 0, r = 1;
    while(!f(r)) r*=2;
    for (int i = 0; i < 100; ++i) {
        double mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << setprecision(20) << r << "\n";
    cout << setprecision(20) << a[0] + r << " "; double p = a[0] + r;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if(a[i] > p + r) { cout << a[i] + r << " "; p = a[i] + r; cnt++; }
    }
    while(cnt < 3) cout << 1 << " ", cnt++;
}
