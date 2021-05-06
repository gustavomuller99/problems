#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int k; cin>>k;
    if(k%2) cout << -1;
    else {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k/2; ++j) {
                for (int m = 0; m < 2; ++m) {
                    for (int l = 0; l < k/2; ++l) {
                        if(i%2==0) {
                            if(j%2==0) {
                                if(l%2) cout << "bb";
                                else cout << "ww";
                            }
                            else {
                                if(l%2) cout << "ww";
                                else cout << "bb";
                            }
                        } else {
                            if(j%2==0) {
                                if(l%2) cout << "ww";
                                else cout << "bb";
                            }
                            else {
                                if(l%2) cout << "bb";
                                else cout << "ww";
                            }
                        }
                    }
                    cout << "\n";
                }
            }
            cout << "\n";
        }
    }
}
