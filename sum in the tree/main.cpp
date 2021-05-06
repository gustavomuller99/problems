#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, k; cin>>n;
    vector<vector<int>> t(n+1);
    vector<ll> s(n+1);
    for (int i = 2; i <= n; ++i) {
        cin>>k;
        t[k].push_back(i);
    }
    for (int j = 1; j <= n; ++j) {
        cin>>k;
        s[j] = k;
    }
    queue<int> q;
    q.push(1); ll sum=s[1];
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        ll c = LONG_LONG_MAX;
        for(int x : t[f]) {
            if(s[x] == -1) s[x] = s[f];
            else if(s[x] - s[f] < 0) {cout<<"-1"<<endl; return 0;}
            else sum+=s[x]-s[f];
            if(s[x] < c) c = s[x];
            q.push(x);
        }
        if(!t[f].empty()) sum-= (c-s[f]) * (t[f].size()-1);
    }
    cout<<sum<<endl;
}
