#include <bits/stdc++.h>
using namespace std;
int main() {

    int n; cin>>n;
    int a[n+1], k;
    for (int i=0;i<n;++i) {
        cin>>k;a[k] = i;
    }
    int ans=0; vector<int> s(n);
    for (int j=0; j<n;++j) {
        cin>>k; int pos = (j-a[k]+n)%n;
        s[pos]++;
        if(s[pos] > ans) ans=s[pos];
    }
    cout<<ans<<endl;
}
