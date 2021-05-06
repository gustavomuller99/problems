#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
bool is_prime(ll k) {
    if(k%2==0) return false;
    for (int i=3;i*i<=k;i+=2) {
        if(k%i==0) return false;
    }
    return true;
}
int main() {
    int t; cin>>t; while(t--) {
        ll n; cin>>n;
        vector<int> d;
        while(n%2==0) {n=n/2; d.push_back(2);}
        for (ll i=3;i*i<=n&&n!=1;++i) {
            if(is_prime(i) && n%i==0) {
                while(n%i==0) {n=n/i; d.push_back(i);}
            }
        }
        if(n!=1) d.push_back(n);
        ll a=d[0],b=1,c=1;
        int i;
        for (i=1;i<d.size();++i) {
            b*=d[i];
            if(b!=a) break;
        }
        for (int j=i+1;j<d.size();++j) {
            c*=d[j];
        }
        if(a!=b && b!=c && c!=a && c>=2 && b>=2 && a>=2) {
            cout<<"YES "<<a<<" "<<b<<" "<<c<<endl;
        } else cout<<"NO"<<endl;
    }
}
