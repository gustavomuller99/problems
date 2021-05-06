#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    cin>>t; while(t--) {
        cin>>n; vector<int> a(n);for (int i=0;i<n;++i) { cin>>a[i]; }
        int i=0;
        for (int l=1;a[l]<a[i] && l<n;++l) { i = l; }
        int j=i;
        for (int l=i+1;a[l]>a[j] && l<n;++l) {  j=l; }
        (j != n-1) ? cout<<"YES"<<endl<<i+1<<" "<<j+1<<" "<<j+2<<endl : cout<<"NO"<<endl;
    }
}
