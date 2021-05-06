#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        string d; cin>>d;
        vector<int> ans(n+1);
        int l = 0;
        while(l != n) {
            int cur = 0, pv = l, dir = 1;
            if(d[l] == 'L') { l++; continue; }
            while((dir == 1 && d[l] == 'R') || (dir == 0 && d[l] == 'L')) {
                l++;
                dir = !dir;
            }
            for (int i = l; i >= pv; --i) {
                if(dir) ans[i] += cur;
                cur++;
                dir = !dir;
            }
        }
        int r = n;
        while(r != 0) {
            int cur = 0, pv = r, dir = 0;
            if(d[r-1] == 'R') { r--; continue; }
            while((dir == 1 && d[r-1] == 'R') || (dir == 0 && d[r-1] == 'L')) {
                r--;
                dir = !dir;
            }
            for (int i = r; i <= pv; ++i) {
                if(!dir) ans[i] += cur;
                cur++;
                dir = !dir;
            }
        }
        for(int x : ans) cout << x+1 << " "; cout << "\n";
    }
}
