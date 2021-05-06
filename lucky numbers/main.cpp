#include <bits/stdc++.h>
using namespace std;
void print(int n) {
    for (int i = 0; i < n/2; ++i) cout << 4;
    for (int i = n/2; i < n; ++i) cout << 7;
}
int main() {
    string a; cin>>a;
    if(a.size()%2) print(a.size() + 1);
    else {
        string ans; int i, cnt4 = 0, cnt7 = 0;
        vector<int> p;
        for (i = 0; a[i] == '4' || a[i] == '7' ; ++i) {
            ans.push_back(a[i]);
            if(a[i] == '4') p.push_back(i), cnt4++;
            else cnt7++;
        }
        if(i == a.size()) {
            if(cnt4 == cnt7) for (int j = 0; j < ans.size(); ++j) cout << ans[j];
            else {
                bool ps = false;
                while(i > 0) {
                    i--;
                    if(a[i] == '4') {
                        cnt4--;
                        if(cnt4 > cnt7 + 1 && a.size() - (i+1) >= cnt4-(cnt7+1) && (a.size()-(i+1))%2 == (cnt4-(cnt7+1))%2) { ps = true; break; }
                        if(cnt7 + 1 > cnt4 && a.size() - (i+1) >= cnt7+1-cnt4 && (a.size()-(i+1))%2 == (cnt7+1-cnt4)%2) { ps = true; break; }
                        if(cnt7 + 1 == cnt4 && (a.size()-(i+1))%2==0) { ps = true; break; }
                    }
                    else cnt7--;
                }
                if(ps) {
                    ans[i] = '7'; cnt7++; i++;
                    for (; i < a.size(); ++i) ans[i] = '4', cnt4++, p.push_back(i);
                    while(!p.empty() && cnt4 != cnt7) {
                        ans[p[p.size() - 1]] = '7'; cnt7++, cnt4--;
                        p.pop_back();
                    }
                    for (int j = 0; j < ans.size(); ++j) cout << ans[j];
                }
                else print(a.size() + 2);
            }
        } else if(a[i] <= '4') {
            for (; i < a.size(); ++i) ans.push_back('4'), cnt4++, p.push_back(i);
            while(!p.empty() && cnt4 != cnt7) {
                ans[p[p.size() - 1]] = '7'; cnt7++, cnt4--;
                p.pop_back();
            }
            if(cnt4 == cnt7) for (int j = 0; j < ans.size(); ++j) cout << ans[j];
            else print(a.size() + 2);
        } else if(a[i] <= '7') {
            ans.push_back('7'), cnt7++, i++;
            for (; i < a.size(); ++i) ans.push_back('4'), cnt4++, p.push_back(i);
            while(!p.empty() && cnt4 != cnt7) {
                ans[p[p.size() - 1]] = '7'; cnt7++, cnt4--;
                p.pop_back();
            }
            if(cnt4 == cnt7) for (int j = 0; j < ans.size(); ++j) cout << ans[j];
            else print(a.size() + 2);
        } else {
            if(p.empty()) print(a.size() + 2);
            else {
                ans[p[p.size() - 1]] = '7'; cnt7++, cnt4--; p.pop_back();
                for (; i < a.size(); ++i) ans.push_back('4'), cnt4++, p.push_back(i);
                while(!p.empty() && cnt4 != cnt7) {
                    ans[p[p.size() - 1]] = '7'; cnt7++, cnt4--;
                    p.pop_back();
                }
                if(cnt4 == cnt7) for (int j = 0; j < ans.size(); ++j) cout << ans[j];
                else print(a.size() + 2);
            }
        }
    }
}
