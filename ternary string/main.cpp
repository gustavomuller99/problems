#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        string n;
        cin >> n;
        int a, b, c;
        a = b = c = 0;
        int d = INT_MAX;
        for(int i = 0; i < n.size(); i++) {
            switch (n[i]) {
                case '1' :
                    a = i + 1;
                    break;
                case '2' :
                    b = i + 1;
                    break;
                case '3' :
                    c = i + 1;
                    break;
            }
            if(a && b && c) {
                int dist = max(a, max(b, c)) - min(a, min(b, c)) + 1;
                if (dist < d) d = dist;
            }
        }

        if(a && b && c) cout << d << endl;
        else cout << "0" << endl;

    }

}
