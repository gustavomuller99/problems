#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> t(n+1);
    int r;
    int p, c;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> p >> c;
        if(p==-1) r=i+1;
        else t[p].emplace_back(i+1, c);
        if(c) q.push(i+1);
    }
    bool e = true;
    while(!q.empty() ) {
        int top = q.front(); vector<pair<int,int>> child = t[top];
        q.pop();
        bool remove = true;
        for(auto k : child) {
            remove &= k.second;
        }
        if(remove) {e = false; cout << top << " ";}
    }
    if(e) cout << "-1" << endl;
}
