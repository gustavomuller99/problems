#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int>> dsu(100000, {0,0});
vector<int> sizes;
const int MOD = 1e9 + 7;
ll pow(ll a, ll b, ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}
void make_set(int v) {
    dsu[v].second = 1;
    dsu[v].first = 1;
}
int find_set(int v) {
    if(dsu[v].first == 1) return v;
    return dsu[v].second = find_set(dsu[v].second);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(dsu[a].second < dsu[b].second) swap(a, b);
        auto it = find(sizes.begin(), sizes.end(), dsu[a].second);
        if(it != sizes.end()) {
            sizes.erase(it);
        }
        it = find(sizes.begin(), sizes.end(), dsu[b].second);
        if(it != sizes.end()) {
            sizes.erase(it);
        }
        dsu[a].second += dsu[b].second;
        dsu[b].second = a;
        dsu[b].first = 0;
        sizes.push_back(dsu[a].second);
    }
}
int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        if(!x) {
            if(dsu[u].second == 0) make_set(u);
            if(dsu[v].second == 0) make_set(v);
            union_sets(u, v);
        }
    }
    ll ans = (ll) (pow(n, k, MOD) - n) % MOD;
    for(auto x : sizes) {
        ans -= (ll) (pow(x, k, MOD) - x);
        ans += MOD;
        ans %= MOD;
    }
    cout << ans << endl;

}
