#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n; cin>>n;
    if(n%2) cout << 0;
    else cout << setprecision(20) << pow(2, (n/2));
}
