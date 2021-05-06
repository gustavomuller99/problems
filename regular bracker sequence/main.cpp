#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int sum = 0;
        queue<int> q;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == ')') sum--;
            else if(s[i] == '(') sum++;
            else q.push(i);
            while(sum < 0 && !q.empty()) {
                int k = q.front(); q.pop();
                s[k] = '('; sum++;
            }
        }
        sum = 0;
        q = queue<int>();
        for (int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == '(') sum--;
            else if(s[i] == ')') sum++;
            else q.push(i);
            while(sum < 0 && !q.empty()) {
                int k = q.front(); q.pop();
                s[k] = ')'; sum++;
            }
        }
        while(!q.empty()) {
            int k = q.front(); q.pop();
            s[k] = ')';
            if(!q.empty()) {
                k = q.front(); q.pop();
                s[k] = '(';
            }
        }
        sum = 0; bool ans = true;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == ')') sum--;
            else if(s[i] == '(') sum++;
            if(sum < 0) ans = false;
        }
        if(ans && sum == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
