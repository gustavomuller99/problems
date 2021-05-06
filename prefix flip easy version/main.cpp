#include <bits/stdc++.h>
using namespace std;

int main() {

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string a; cin>>a;
        string b; cin>>b;
        vector<int> moves;
        /* 3n moves
        for (int i=n-1;i>=0;--i) {
            if(a[i] != b[i]) {moves.push_back(i+1); moves.push_back(1); moves.push_back(i+1);}
        }
        */
        for (int i=n-1;i>=0;--i) {
            if(a[i] != b[i]) {
                if(a[i] != a[0]) {
                    moves.push_back(1);
                    a[0] = (a[0]=='1' ? '0' : '1');
                }
                moves.push_back(i+1);
                for (int j=0;j<=i/2;++j) {
                    char c = a[j];
                    a[j] = (a[i-j]=='1' ? '0' : '1');
                    a[i-j] = (c=='1' ? '0' : '1');
                }
            }
        }
        cout<<moves.size()<<" ";
        for(int k : moves) {cout<<k<<" ";}
        cout<<endl;
    }
}
