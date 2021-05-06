#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--) {
        string i;
        cin>>i;
        pair<int, char> r = {0, 'R'}, p = {0, 'P'}, s = {0, 'S'};
        for (int j = 0; j < i.size(); ++j) {
            if(i[j] == 'R') p.first++;
            else if(i[j] == 'P') s.first++;
            else if(i[j] == 'S') r.first++;
        }
        pair<int,char> ans = max(r, max(p ,s));
        for (int k = 0; k < i.size(); ++k) {
            cout << ans.second;
        } cout << endl;
    }

}