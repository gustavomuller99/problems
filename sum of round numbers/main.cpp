#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k=0; cin >> n;
        vector<int> s;
        while(n > 0) {
            if(n % 10) { s.push_back((n % 10) * (pow(10, k))); }
            n /= 10; k++;
        }
        cout << s.size() << endl;
        for (int x : s) { cout << x << " "; } cout << endl;
    }
}
