#include <bits/stdc++.h>
using namespace std;
int prefix(string s) {
    vector<int> p(s.size());
    p[0] = -1;
    int k = -1;
    for (int i = 1; i < s.size(); ++i) {
        while(k > -1 && s[k+1] != s[i]) k = p[k];
        if(s[k+1] == s[i]) k++;
        p[i] = k;
    }
    return p[s.size() - 1];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        string a, ans, p; cin>>a;
        int l = -1, p1 = 0, p2 = 0;
        for (int i = 0; i < a.size() / 2; ++i) {
            if(a[i] == a[a.size() - i - 1]) l++;
            else break;
        }

        for (int i = 0; i <= l; ++i) ans.push_back(a[i]);

        {
            for (int i = l + 1; i < a.size() - l - 1; ++i) p.push_back(a[i]);
            p.push_back('#');
            for (int i = a.size() - l - 2; i > l; --i) p.push_back(a[i]);
            p1 = prefix(p);
        }
        p = "";
        {
            for (int i = a.size() - l - 2; i > l; --i) p.push_back(a[i]);
            p.push_back('#');
            for (int i = l + 1; i < a.size() - l - 1; ++i) p.push_back(a[i]);
            p2 = prefix(p);
        }

        if(p1 > p2) for (int i = l + 1; i <= l + 1 + p1; ++i) ans.push_back(a[i]);
        else for (int i = (int) a.size() - l - 2; i >= (int) a.size() - l - 2 - p2; --i) ans.push_back(a[i]);
        for (int i = l; i >= 0; --i) ans.push_back(a[i]);
        cout << ans << "\n";

    }
}
