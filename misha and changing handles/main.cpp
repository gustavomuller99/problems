#include <bits/stdc++.h>
using namespace std;

map<string, string> nm;
int main() {
    int q; cin>>q;
    while(q--) {
        string o, n; cin>>o>>n;
        auto it = nm.find(o);
        if(it != nm.end()) {
            string og = it->second;
            nm.erase(it); nm[n] = og;
        }
        else nm[n] = o;
    }
    cout << nm.size() << endl;
    for(auto k : nm) {
        cout << k.second << " " << k.first << endl;
    }
}
