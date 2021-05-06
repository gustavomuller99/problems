#include <bits/stdc++.h>
using namespace std;
struct p{int x,y,z;};
int c[102][102][102] = {0};
bool ck(int x, int y, int z) {
    if(!c[x][y][z]) return false;
    if(c[x-1][y][z] && c[x+1][y][z]) return true;
    if(c[x][y-1][z] && c[x][y+1][z]) return true;
    if(c[x][y][z-1] && c[x][y][z+1]) return true;
    if(c[x-1][y][z] && c[x][y+1][z] && !c[x-1][y+1][z]) return true;
    if(c[x-1][y][z] && c[x][y][z+1] && !c[x-1][y][z+1]) return true;
    if(c[x][y-1][z] && c[x+1][y][z] && !c[x+1][y-1][z]) return true;
    if(c[x][y-1][z] && c[x][y][z+1] && !c[x][y-1][z+1]) return true;
    if(c[x][y][z-1] && c[x+1][y][z] && !c[x+1][y][z-1]) return true;
    if(c[x][y][z-1] && c[x][y+1][z] && !c[x][y+1][z-1]) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            string r; cin>>r;
            for (int l = 1; l <= k; ++l) c[i][j][l] = r[l-1] == '1' ? 1 : 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if(ck(i,j,l)) ans++;
            }
        }
    }
    cout<<ans;
}
