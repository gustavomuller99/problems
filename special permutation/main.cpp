#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n <= 3) cout << "-1" << endl;
        else {
            vector<int> o;
            int a = n%2;
            for (int i = 2; i <= n-a; i+=2) {
                o.push_back(i);
            }
            o.push_back(n-a-3);
            if(a) o.push_back(n);
            o.push_back(n-a-1);
            for (int i = n-a-5; i > 0; i-=2) {
                o.push_back(i);
            }
            for(int k : o) {
                cout << k << " ";
            } cout << endl;
        }
    }
}
