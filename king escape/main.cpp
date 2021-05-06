#include <bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by, cx, cy;
vector<vector<int>> v;
vector<int> mv = {0, 1, -1};
int dfs(int x, int y) {
    if(x==cx&&y==cy) return 1;
    v[x][y] = 1;
    vector<bool> m(8,false);
    bool ans = false;
    int k = -1;
    for (int j=0;j<3;++j) {
        for (int i=0;i<3;++i) {
            int dx = mv[j]; int dy = mv[i];
            if(x+dx >= 0 && x+dx < n && y+dy >= 0 && y+dy < n) {
                if (!v[x + dx][y + dy] &&
                    x + dx != ax && y + dy != ay &&
                    (abs(y + dy - ay) != abs(x + dx - ax))) {
                    m[k] = dfs(x + dx, y + dy);
                }
            }
            k++;
        }
    }
    for (int i=0;i<8;++i) {
        ans |= m[i];
    } return ans;
}
int main() {
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    /*
    ax--;ay--;bx--;by--;cx--;cy--;
    v.resize(n);
    for (int i=0;i<n;++i) {v[i].resize(n);}
    cout<<(dfs(bx, by)==0 ? "NO" : "YES")<<endl;
    smarter solution */
    int dx = ax-bx;
    int dy = ay-by;
    if(dx<0&&ax-cx<0&&dy<0&&ay-cy<0) {cout<<"YES"<<endl;}
    else if(dx>0&&ax-cx>0&&dy<0&&ay-cy<0) {cout<<"YES"<<endl;}
    else if(dx>0&&ax-cx>0&&dy>0&&ay-cy>0) {cout<<"YES"<<endl;}
    else if(dx<0&&ax-cx<0&&dy>0&&ay-cy>0) {cout<<"YES"<<endl;}
    else cout<<"NO"<<endl;
}
