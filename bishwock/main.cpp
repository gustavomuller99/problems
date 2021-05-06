#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(2); int ans = 0;
    for (int i = 0; i < 2; ++i) cin>>s[i];
    for (int i = 0; i < s[0].size() - 1; ++i) {
        if(s[0][i] + s[0][i+1] + s[1][i] == 144) s[0][i] = s[0][i+1] = s[1][i] = 'X', ans++;
        if(s[0][i+1] + s[1][i] + s[1][i+1] == 144) s[0][i+1] = s[1][i] = s[1][i+1] = 'X', ans++;
        if(s[0][i] + s[0][i+1] + s[1][i+1] == 144) s[0][i] = s[0][i+1] = s[1][i+1] = 'X', ans++;
        if(s[0][i] + s[1][i] + s[1][i+1] == 144) s[0][i] = s[1][i] = s[1][i+1] = 'X', ans++;
    }
    cout << ans;
}
