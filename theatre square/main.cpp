#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {

    ll n, m, a;
    cin >> n >> m >> a;

    ll x = (m / a + bool (m % a));
    ll y = (n / a + bool (n % a));
    cout << x * y << endl;

}
