#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, d; cin >> n >> m;
        string in[n];
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < n; ++i) {
            string cf = in[i];
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    string ch = cf;
                    ch[k] = in[j][k];
                    for (int l = 0; l < n; ++l) {
                        d = 0;
                        for (int o = 0; o < m; ++o) {
                            if(ch[o] != in[l][o]) d++;
                        }
                        if(d>1) break;
                    }
                    if(d<=1) { cout << ch << endl; break; }
                }
                if(d<=1) break;
            }
            if(d<=1) break;
        }
        if(d>1) cout << "-1" << endl;
    }
}
