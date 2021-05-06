#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(26);
    for (int i = 0; i < 26; ++i) a[i] = i;
    string s; int n, m; cin>>n>>m>>s;
    for (int i = 0; i < m; ++i) {
        char x,y; cin>>x>>y; x -= 'a', y -= 'a';
        for (int j = 0; j < 26; ++j) {
            if(a[j] == x) a[j] = y;
            else if(a[j] == y) a[j] = x;
        }
    }
    for (int k = 0; k < n; ++k) s[k] = a[s[k]-'a'] + 'a';
    cout << s;
}
