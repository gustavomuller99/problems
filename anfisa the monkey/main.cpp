#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,a,b; cin>>k>>a>>b;
    string in; cin>>in;
    vector<int> s(k);
    int t=0;
    for (int i = 0; i < k; ++i) {
        s[i] = a; t += a;
    }
    if(t>in.size()) {cout<<"No solution"<<endl; return 0;}
    for (int i = t; i < in.size(); ++i) {
        s[(i+1)%k]++;
        if(s[(i+1)%k]>b) {cout<<"No solution"<<endl; return 0;}
    }
    for (int j=0,p=0,n=s[0];j<k;++j) {
        for (int i = p; i < n; ++i) {
            cout<<in[i];
        } cout<<endl;
        p=n;
        n+=s[j+1];
    }
}
