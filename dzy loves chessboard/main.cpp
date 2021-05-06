#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    string o[n];
    for (int i=0;i<n;++i) {
        cin>>o[i];
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if(o[i][j]=='.') {o[i][j] = (i+j) % 2 ? 'W' : 'B';}
            cout<<o[i][j];
        }
        cout<<endl;
    }
}
