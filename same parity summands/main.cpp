#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll a = n - (k - 1);
        if(a%2 == 1 && a>0) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; ++i) {
                cout << "1 ";
            } cout << a << endl;
            continue;
        }
        a = n - 2*(k - 1);
        if(a%2 == 0 && a>0) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; ++i) {
                cout << "2 ";
            } cout << a << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}
