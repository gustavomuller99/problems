#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        string a,b; cin>>a>>b;
        int c=0,d;
        for (auto i=b.rbegin(); i<b.rend();++i) {
            if(*i=='1') break;
            c++;
        }
        if(c>a.size()-1) {cout<<0<<endl; continue;}
        d=c;
        for (int i=a.size()-1-c;i>=0;--i) {
            if(a[i]=='1') break;
            d++;
        }
        cout<<d-c<<endl;
    }
}
