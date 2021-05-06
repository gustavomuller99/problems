#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int t;
    cin >> t;

    while(t--) {

        ll n;
        cin >> n;
        vector<ll> a(n+1);

        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            a[x]++;
        }
        ll hi = *max_element(a.begin(), a.end());
        ll diff = n - count(a.begin(), a.end(), 0);
        if(hi > diff) {
            cout << min(diff+1,hi-1) << endl;
        } else cout << hi << endl;

    }

}
