#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string a; string b; cin>>a; cin>>b;
        a += '0'; b += '0';
        vector<int> ma, mb;
        for (int i=0;i<n;++i) {
            if(a[i] != a[i+1]) ma.push_back(i+1);
            if(b[i] != b[i+1]) mb.push_back(i+1);
        }
        ma.insert(ma.end(), mb.rbegin(), mb.rend());
        cout<<ma.size()<<" ";
        for(int k : ma) cout<<k<<" ";
        cout<<endl;
    }
}
