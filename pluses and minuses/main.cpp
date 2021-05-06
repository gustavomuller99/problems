#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

    int t;
    cin >> t;

    /*
     * reasoning: because of line 18 we are counting the number steps we can take with the 'current' cur,
     * when cur reaches -1, we set it to 0, because in the next iteration (that never occurs in this solution) he would
     * reach the same point with cur+1, which is 0.
     * because we are setting cur to 0 dynamically, we do res += i+1 so res adds the number of steps to reach the same point
     * in the next iteration.
     */
    while(t--) {
        string m;
        cin >> m;
        long long res = 0, cur = 0;

        for(int i = 0; i < m.size(); i++) {
            res++;
            cur += (m[i] == '+') ? 1 : -1;
            if(cur < 0) {
                cur = 0;
                res += i+1;
            }
        } cout << res << endl;


        /* not smart, concatenate +'s and -'s
        vector<pair<int,char>> k(1);
        k[0].first++; k[0].second = m[0];
        for(int i = 1; i < m.size(); i++) {
            if(m[i] == k[k.size() - 1].second) {
                k[k.size() - 1].first++;
            } else {
                k.emplace_back(make_pair(1, m[i]));
            }
        }
        bool ok = false;
        ll res = 0, init = 0, cur = 0;
        while(!ok) {
            ok = true;
            cur = init;
            init++;
            for(auto j : k) {
                if(j.second == '-') {
                    if(j.first > cur) {
                        res += cur + 1;
                        ok = false;
                        break;
                    } else {
                        res += j.first;
                        cur -= j.first;
                    }
                } else {
                    cur += j.first;
                    res += j.first;
                }
            }
        }
        cout << res << endl;
        */

    }

}
