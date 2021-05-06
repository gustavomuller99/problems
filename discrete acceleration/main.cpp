#include <bits/stdc++.h>
using namespace std;
int n; double l;
vector<double> c;
vector<double> a, b;
bool f(double x) {
    int pa, pb, lx = 0, rx = n + 2;
    while(rx > lx + 1) {
        int mid = (lx + rx) / 2;
        if(a[mid] < x) lx = mid;
        else rx = mid;
    }
    pa = lx;
    lx = -1, rx = n + 1;
    while (rx > lx + 1) {
        int mid = (lx + rx) / 2;
        if(b[mid] < x) rx = mid;
        else lx = mid;
    }
    pb = rx;
    return c[pa] + (x - a[pa])*(pa + 1) > c[pb] - (x - b[pb])*(n + 2 - pb);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while(t--) {
        cin >> n >> l;
        c = vector<double> (n + 2);
        a = vector<double> (n + 2);
        b = vector<double> (n + 2);

        c[0] = 0; c[n+1] = l;
        for (int i = 1; i < n + 1; ++i) cin >> c[i];

        a[0] = 0;
        b[n+1] = 0;
        for (int i = 1; i < n + 2; ++i) a[i] = (c[i] - c[i-1]) / i + a[i - 1];
        for (int i = 1; i < n + 2; ++i) b[n+1-i] = (c[n+2-i] - c[n+1-i]) / i + b[n+2-i];

        double lx = 0, rx = l;
        for (int i = 0; i < 100; ++i) {
            double mid = (lx + rx) / 2;
            if(f(mid)) rx = mid;
            else lx = mid;
        }
        cout << setprecision(20) << rx << "\n";
    }
}
