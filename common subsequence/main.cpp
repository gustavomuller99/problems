#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<int> a(n);
        int ans = 0;
        for (int i=0;i<n;++i) {cin>>a[i];}
        for (int i=0;i<m;++i) {
            int k; cin>>k;
            for (int j=0;j<n;++j) {if(k == a[j]) ans = k;}
        }
        if(ans) cout<<"YES"<<endl<<1<<" "<<ans<<endl;
        else cout<<"NO"<<endl;
    }

}
