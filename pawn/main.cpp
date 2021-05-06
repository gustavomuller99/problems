#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k,col,mx=-1; cin>>n>>m>>k;k++;
    vector<char> ans;
    int c[n][m], d[n][m][k];
    pair<int,int> p[n][m][k];
    for (int i = 0; i < n; ++i) {
        string in; cin>>in;
        for (int j = 0; j < m; ++j) {
            c[i][j] = in[j] - '0';
        }
    }
    for (int i = 0; i < m; ++i) {
        memset(d, -1, sizeof(d));
        d[n-1][i][c[n-1][i] % k] = c[n-1][i];
        for (int i1 = n-2; i1 >= 0; --i1) {
            for (int j1 = 0; j1 < m; ++j1) {
                for (int k1 = 0; k1 < k; ++k1) {
                    if(j1 && d[i1+1][j1-1][k1] != -1 && d[i1+1][j1-1][k1] + c[i1][j1] > d[i1][j1][(k1 + c[i1][j1]) % k])
                        d[i1][j1][(k1 + c[i1][j1]) % k] = d[i1+1][j1-1][k1] + c[i1][j1], p[i1][j1][(k1 + c[i1][j1]) % k] = {k1, -1};
                    if(j1 < m-1 && d[i1+1][j1+1][k1] != -1 && d[i1+1][j1+1][k1] + c[i1][j1] > d[i1][j1][(k1 + c[i1][j1]) % k])
                        d[i1][j1][(k1 + c[i1][j1]) % k] = d[i1+1][j1+1][k1] + c[i1][j1], p[i1][j1][(k1 + c[i1][j1]) % k] = {k1, +1};
                }
            }
        }
        int col1 = -1;
        for (int j = 0; j < m; ++j) if(d[0][j][0] > mx) mx = d[0][j][0], col1 = j;
        if(col1 != -1) {
            int k1 = 0;
            vector<char> a;
            for (int i1 = 0; i1 < n-1; ++i1) {
                if(p[i1][col1][k1].second == -1) k1 = p[i1][col1][k1].first, col1--, a.push_back('R');
                else k1 = p[i1][col1][k1].first, col1++, a.push_back('L');
            }
            ans = a;
            col = col1;
        }
    }
    if(mx == -1) cout << -1;
    else {
        cout << mx << "\n" << col+1 << "\n";
        for (auto i = ans.rbegin(); i < ans.rend(); ++i) cout << *i;
    }
}
