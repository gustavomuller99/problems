#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        ll u,v; cin>>u>>v;
        if(u > v) cout << "NO\n";
        else {
            bool ans = true;
            while(v) {
                if(!u) {ans = false; break;}
                ll l = 1, lu = 0, lv = 0;
                while(!lu || !lv) {
                    if(lu == 0 && (u & l) == l) lu = l;
                    if(lv == 0 && (v & l) == l) lv = l;
                    l *= 2;
                }
                if(lu > lv) ans = false;
                u -= lu, v -= lv;
            }
            cout << (ans ? "YES\n" : "NO\n");
        }
    }
}
