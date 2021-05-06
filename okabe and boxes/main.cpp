    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int n; cin>>n;
        int ans = 0, k = 1;
        stack<int> s;
        for (int i = 0; i < 2*n; ++i) {
            string c; cin>>c;
            if(c[0] == 'a') {
                int a; cin>>a;
                s.push(a);
            } else {
                if(!s.empty()) {
                  if(s.top() == k) s.pop();
                  else ans++, s = stack<int> ();
                }
                k++;
            }
        }
        cout<<ans;
    }
