#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n; int k = 2*n;
        vector<int> hpo;
        vector<int> in(k);
        for (int i=0;i<k;++i) {
            cin>>in[i];
        }
        int curr=0;
        for (int j=1;j<k;++j) {
            if(in[j] > in[curr]) {hpo.push_back(j-curr); curr = j;}
        } hpo.push_back(k-curr);
        bool vis[n+1]; vis[0] = true;
        fill(vis, vis + n + 1, false);
        vis[0] = true; int a[n+1];
        int m = hpo.size();
        for(int l = 0; l < m; l++) {
            int r = l;
            while(r < m && hpo[r] == hpo[l]) r++;
            fill(a, a + n + 1, 0);
            for(int i = hpo[l]; i <= n; i++) {
                if(!vis[i] && vis[i - hpo[l]] && a[i - hpo[l]] < r - l) {
                    a[i] = a[i - hpo[l]] + 1;
                    vis[i] = true;
                }
            }
            l = r - 1;
        }
        cout << (vis[n] ? "YES" : "NO") << '\n';
    }
}
