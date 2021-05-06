#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        /* ((k-1)/(n-1))*n + (k - (n-1)*((k-1)/(n-1))) */
        cout <<  (k-1)/(n-1) + k << "\n";
    }
}
