#include <bits/stdc++.h>
using namespace std;

/* find a minimum cost flow with value K. if k is infinity,
 * the problem is min-cost max-flow.
 * does shortest paths like edmonds-karp but using costs,
 * in this case uses spfa - extension of bellman-ford */

vector<vector<int>> g;
vector<vector<int>> cost, capacity;
int n, m, source, sink;

int minimum_cost() {
    int flow = 0, cst = 0;
    while(true) {
        /* spfa to find shortest cost path in flow */
        vector<int> d(n + m + 2, INT_MAX), p(n + m + 2, -1); d[source] = 0; /* distance and parent */
        vector<bool> inqueue(n + m + 2, false);
        queue<int> q; q.push(source);
        while(!q.empty()) {
            int v = q.front(); q.pop();
            inqueue[v] = false;
            for(int adj : g[v]) {
                if(capacity[v][adj] && d[adj] > d[v] + cost[v][adj]) {
                    d[adj] = d[v] + cost[v][adj];
                    p[adj] = v;
                    if(!inqueue[adj]) {
                        inqueue[adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
        /* end spfa */
        if(p[sink] == -1) break; /* no more augmentation paths */
        /* find max flow not exceeding k - flow */
        int f = INT_MAX;
        int cur = sink;
        while(cur != source) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
        /* apply flow */
        flow += f;
        cst += f * d[sink]; /* update cost function accordingly */
        cur = sink;
        while(cur != source) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    return cst;
}

/* add edge to flow */
void add(int u, int v, int cst, int cap) {
    g[u].push_back(v), g[v].push_back(u);
    cost[u][v] = cst, cost[v][u] = -cst;
    capacity[u][v] = cap, capacity[v][u] = 0;
}

int main() {
    cin >> m >> n;
    g.resize(n + m + 2);
    cost.resize(n + m + 2, vector<int> (n + m + 2));
    capacity.resize(n + m + 2, vector<int> (n + m + 2));
    source = 0, sink = n + m + 1;
    vector<pair<int,bool>> jiro;
    vector<int> fox(n);
    for (int i = 1; i <= m; ++i) {
        string t; int s; cin>>t>>s;
        add(n + i, sink, 0, 1);
        jiro.push_back({s, t[0]=='A'});
    }
    for (int i = 0; i < n; ++i) {
        cin>>fox[i];
        add(source, i + 1, 0, 1);
    }
    if(n <= m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (jiro[j].second) {
                    if (fox[i] >= jiro[j].first) add(i + 1, n + j + 1, -(fox[i] - jiro[j].first), 1);
                }
            }
        }
    } else {

    }
    int min_cost = -minimum_cost();
    for (int i = 1; i <= n; ++i) {
        if(capacity[0][i]) min_cost += fox[i-1];
    }
    cout << min_cost;
}
