#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool is_prime(int n) {
    if(n == 3 || n == 2) return true;
    if(!(n % 2)) return false;
    ll k = floor(sqrt(n));
    for(int i = 3; i <= k; i+=2) {
        if(!(n % i)) return false;
    }
    return true;
}

int main() {

    int t;
    cin >> t;
    while(t--) {

        bool a;
        ll n;
        cin >> n;

        if(n == 1) {cout << "FastestFinger" << endl; continue;}
        if(n % 2) {cout << "Ashishgup" << endl; continue;}
        ll c = n;
        int bit = 0;
        while(c!=0) {
            if(c & 1) bit++;
            c = c >> 1;
        }
        if(bit == 1 && n != 2) {cout << "FastestFinger" << endl; continue;}
        n /= 2; if(n == 1) {cout << "Ashishgup" << endl; continue;}
        if(is_prime(n)) {cout << "FastestFinger" << endl; continue;}
        cout << "Ashishgup" << endl;
    }


}
