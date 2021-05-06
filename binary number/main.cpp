#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in; cin >> in;
    int op = 0; bool c = false;
    if(in.size() == 1 || count(in.begin(), in.end(), '1') == 1) { cout << in.size() - 1; return 0; }
    for (auto i = in.rbegin(); i != in.rend(); ++i) {
        char p = *i;
        if((p == '1' && !c) || (p == '0' && c)) { op += 2; c = true; }
        else if(p == '1') { op++; }
        else if(p == '0') { op++; c = false; }
    }
    cout << op;
}

/*
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in; cin >> in;
    int cnt = 0, index = 0;
    for (int i = 0; i < in.size(); ++i) { if(in[i] == '1') cnt++, index = i; }
    cout << (index != 0 ? in.size() + index - cnt + 2 : in.size() - 1);
 */
