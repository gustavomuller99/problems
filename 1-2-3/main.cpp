#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
map<pair<int,int>, int> mp;
int am[3][3],bm[3][3],a,b,c;
ll k,kc,bw=0,aw=0;
vector<pair<int,int>> st;
void add(int i, int j) {
    for (; i < j; ++i) {
        if(st[i].first == st[i].second) continue;
        else if((st[i].first == 3 && st[i].second == 2) || (st[i].first == 2 && st[i].second == 1) || (st[i].first == 1 && st[i].second == 3)) aw++;
        else bw++;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>k>>a>>b; kc = k;
    st = {{a, b}};
    for (int i = 0; i < 9; ++i) cin>>am[i/3][i%3];
    for (int i = 0; i < 9; ++i) cin>>bm[i/3][i%3];
    while(1) {
        mp[{a,b}] = st.size();
        int b_c = b;
        b = bm[a-1][b-1];
        a = am[a-1][b_c-1];
        if(mp[{a,b}]) { c = mp[{a,b}]; break; }
        st.emplace_back(a, b);
    }
    k -= c-1;
    if(kc > c-1) add(c-1, st.size());
    aw *= (k/(st.size() - (c-1))); bw *= (k/(st.size() - (c-1)));
    k %= (st.size() - (c-1));
    if(kc > c-1) add(c-1, c-1+k);
    add(0, min(kc, (ll) c-1));
    cout << aw << " " << bw << "\n";
}
