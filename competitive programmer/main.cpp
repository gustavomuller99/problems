#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        string k;
        cin >> k;
        string ans = "red";
        int r = 0;
        int zero = 0;
        int t20 = 0;
        int it = k.size() - 1;
        while(it>=0) {
            int temp = int(k[it] - '0');
            r += temp;
            if(!temp) zero++;
            if(!(temp%2)) t20++;
            it--;
        }
        if(r%3 || !zero || (t20<=1)) ans = "cyan";
        cout << ans << endl;

    }

}
