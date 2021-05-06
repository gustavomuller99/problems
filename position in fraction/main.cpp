#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,pos=-1; cin>>a>>b>>c;
    a = a%b;
    vector<int> d;
    for (int i = 0; i <= b; ++i) {
        if(a == 0) break;
        int k = 0;
        while(a < b) {
            a *= 10, k++;
            if(k > 1) d.push_back(0);
        }
        d.push_back(a/b);
        a = a - (b*(a/b));
    }
    d.push_back((a * 10) / b);
    for (int i = 0; i < d.size(); ++i) {
        if(d[i] == c) { pos = i+1; break; }
    }
    cout << pos;
}
