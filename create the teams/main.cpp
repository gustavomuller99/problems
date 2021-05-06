#include <bits/stdc++.h>
using namespace std;

int t, n, x;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>x;
        vector<int> a(n);
        for (int i=0;i<n;++i) {cin>>a[i];}
        sort(a.begin(), a.end(), greater<>());
        int ans=0,curr=0;
        for (int j=0;j<n;++j) {
            curr++;
            if(curr*a[j]>=x) {ans++;curr=0;}
        }
        cout<<ans<<endl;
    }
}
