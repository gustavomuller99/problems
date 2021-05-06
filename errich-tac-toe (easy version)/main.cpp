#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<string> g(n);
        int r0=0, r1=0, r2=0, r;
        for (int i = 0; i < n; ++i) cin>>g[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(g[i][j] == 'X') {
                    if((i+j)%3==0) r0++;
                    else if((i+j)%3==1) r1++;
                    else if((i+j)%3==2) r2++;
                }
            }
        }
        if(min(r0, min(r1, r2)) == r0) r = 0;
        else if(min(r1, r2) == r1) r = 1;
        else r = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(g[i][j] == 'X' && (i+j)%3 == r) g[i][j] = 'O';
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << g[i] << "\n";
        }
    }
}