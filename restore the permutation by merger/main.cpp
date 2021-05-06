#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> in;
        for (int i=0;i<2*n;++i) { int k; cin>>k; if(find(in.begin(), in.end(), k) == in.end()) in.push_back(k); }
        for (int k : in) { cout<<k<<" ";} cout<<endl;
    }
}
