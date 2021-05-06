#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin>>n>>m;
    vector<string> g(n);
    bool p = true;
    for (int i = 0; i < n; ++i) cin>>g[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(g[i][j] == 'b') p = false;
            else if(g[i][j] == 'w') {
                vector<int> c(4);
                int cl;
                if(j < m-2 && g[i][j+1] == 'b' && g[i][j] == 'w') {
                    if(j > 0) for (int k = 0; k < 4; ++k) if(g[i][j-1] == k) c[k] = 1;
                    if(i > 0) {
                        for (int k = 0; k < 4; ++k) if(g[i-1][j] == k) c[k] = 1;
                        for (int k = 0; k < 4; ++k) if(g[i-1][j+1] == k) c[k] = 1;
                        for (int k = 0; k < 4; ++k) if(g[i-1][j+2] == k) c[k] = 1;
                    }
                    if(j < m-3) for (int k = 0; k < 4; ++k) if(g[i][j+3] == k) c[k] = 1;
                    for (int k = 0; k < 4; ++k) if(!c[k]) cl = k;
                    g[i][j] = cl, g[i][j+1] = cl, g[i][j+2] = cl;
                }
                else if(i < n-2 && g[i+1][j] == 'b' && g[i+2][j] == 'w') {
                    if(i > 0) for (int k = 0; k < 4; ++k) if(g[i-1][j] == k) c[k] = 1;
                    if(j > 0) {
                        for (int k = 0; k < 4; ++k) if(g[i][j-1] == k) c[k] = 1;
                        for (int k = 0; k < 4; ++k) if(g[i+1][j-1] == k) c[k] = 1;
                        for (int k = 0; k < 4; ++k) if(g[i+2][j-1] == k) c[k] = 1;
                    }
                    if(j < m-1) {
                        for (int k = 0; k < 4; ++k) if(g[i][j+1] == k) c[k] = 1;
                        for (int k = 0; k < 4; ++k) if(g[i+1][j+1] == k) c[k] = 1;
                    }
                    for (int k = 0; k < 4; ++k) if(!c[k]) cl = k;
                    g[i][j] = g[i+1][j] = g[i+2][j] = cl;
                } else p = false;
            } else if(g[i][j] == '.') g[i][j] -= 'a';
        }
    }
    if(!p) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << (char) (g[i][j] + 'a');
            } cout << "\n";
        }
    }
}