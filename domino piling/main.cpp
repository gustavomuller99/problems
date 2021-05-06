#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    (n>m) ? cout<<(n/2)*m + (n%2)*(m/2)<<endl : cout<<(m/2)*n + (m%2)*(n/2)<<endl;
}
