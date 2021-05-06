#include <bits/stdc++.h>
using namespace std;
int n, m;
bool v[1000][1000] = {false};
string grid[1000];
void dfs(int i, int j) {
    v[i][j] = true;
    if(i>0) if(!v[i-1][j] && grid[i-1][j] == '#') dfs(i-1,j);
    if(i<n-1) if(!v[i+1][j] && grid[i+1][j] == '#') dfs(i+1,j);
    if(j>0) if(!v[i][j-1] && grid[i][j-1] == '#') dfs(i,j-1);
    if(j<m-1) if(!v[i][j+1] && grid[i][j+1] == '#') dfs(i,j+1);
}
int main() {
    cin>>n>>m;
    vector<pair<int,int>> np;
    for (int i=0;i<n;++i) {cin>>grid[i];}

    int connected=0;
    for (int i=0;i<n;++i) {
        int seg=0;
        for (int j=0;j<m;++j) {
            if(grid[i][j]=='#') {
                if(!v[i][j]) {dfs(i,j); connected++;}
                if(j>0) {if(grid[i][j-1]!='#') seg++;}
                else seg++;
            } else {
                v[i][j] = true;
            }
        }
        if(seg>1) {cout<<"-1"<<endl;return 0;}
    }
    cout<<connected;
}
