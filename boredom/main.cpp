#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100001] = {0};
int main() {
    int n; cin>>n;
    for (int i = 0; i < n; ++i) {
        int k; cin>>k;
        a[k]++;
    }
    a[2] = a[2]*2;
    a[3] = a[3]*3 + a[1];
    for (int i = 4; i <= 100000; ++i) {
           a[i] = a[i]*i + max(a[i-2], a[i-3]);
    }
    cout<<max(a[100001-2], a[100001-1]);
}
