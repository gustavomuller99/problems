#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        bool only1x1 = (2*x < y) ? true : false;
        vector<string> tiles(n);
        for(int i = 0; i < n; i++) {
            cin >> tiles[i];
        }
        int price = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(tiles[i].at(j) == '.') {
                    if(j+1 < m) {
                        if (tiles[i].at(j + 1) == '.') {
                            j += 1;
                            if (only1x1) price += 2 * x;
                            else price += y;
                        } else price += x;
                    } else price += x;
                }
            }
        } cout << price << endl;
    }

}
