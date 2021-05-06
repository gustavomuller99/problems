#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dsu(500000, {0,0});

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
        dsu[a].second += dsu[b].second;
        dsu[b].second = a;
        dsu[b].first = 0;
    }
}
int main() {

    int n, m;
    cin >> n >> m;

    int k, a, b;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> a;
            if(j != 0) {
                if (dsu[a].second == 0) make_set(a);
                else a = find_set(a);
                union_sets(a, b);
            } else {
                if(dsu[a].second == 0) make_set(a);
                else a = find_set(a);
            }
            b = a;
        }
    }
    for (int l = 1; l <= n; ++l) {
        if(dsu[l].second == 0) cout << "1 ";
        else {
            a = find_set(l);
            cout << dsu[a].second << " ";
        }
    } cout << endl;

}
