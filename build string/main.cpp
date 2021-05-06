#include <bits/stdc++.h>
using namespace std;
int src=0,snk=1,ans=0,mx=0;
vector<vector<int>> f;
vector<vector<int>> cst;
vector<vector<int>> cap;
void add(int v, int u, int ct, int cp) {
    f[v].push_back(u); f[u].push_back(v);
    cst[v][u] = ct; cst[u][v] = -ct;
    cap[v][u] = cp;
}
bool spfa() {
    vector<int> d(f.size(), INT_MAX);
    vector<int> p(f.size(), -1);
    vector<bool> iq(f.size());
    d[src] = 0;
    queue<int> q; q.push(src);
    while(!q.empty()) {
        int r = q.front(); q.pop();
        iq[r] = false;
        for(int adj : f[r]) {
            if(cap[r][adj] > 0 && d[adj] > d[r] + cst[r][adj]) {
                d[adj] = d[r] + cst[r][adj];
                p[adj] = r;
                if(!iq[adj]) q.push(adj), iq[adj] = true;
            }
        }
    }
    if(p[snk] == -1) return false;
    int cur = snk, flow = INT_MAX;
    while(cur != src) {
        flow = min(flow, cap[p[cur]][cur]);
        cur = p[cur];
    }
    mx += flow;
    ans += flow * d[snk];
    cur = snk;
    while(cur != src) {
        cap[p[cur]][cur] -= flow;
        cap[cur][p[cur]] += flow;
        cur = p[cur];
    }
    return true;
}
int main() {
    string t; int n; cin>>t>>n;
    vector<int> occ(26);
    f.resize(28 + n);
    cst.resize(28 + n, vector<int>(28 + n));
    cap.resize(28 + n, vector<int>(28 + n));
    for (int i = 0; i < t.size(); ++i) occ[t[i] - 'a']++;
    for (int i = 0; i < 26; ++i) if(occ[i]) add(i+2, snk, 0, occ[i]);
    for (int i = 0; i < n; ++i) {
        string s; int c; cin>>s>>c;
        add(src, i+28, i+1, c);
        occ = vector<int> (26);
        for (int j = 0; j < s.size(); ++j) occ[s[j] - 'a']++;
        for (int j = 0; j < 26; ++j) if(occ[j]) add(i+28, j+2, 0, occ[j]);
    }
    while(true) if(!spfa()) break;
    if(mx != t.size()) cout << -1;
    else cout << ans;
}
