#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int main() {
    cin >> n;
    cin >> l >> r;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int c = 0, left = 0, right = l-1;
    int max, s = l;
    for (int i = left; i <= right; ++i) {
        c += a[i];
    }
    max = c;
    while(right != n-1 || s != l) {
        cout << c << " " << max << " --> ";
        if(s == l) {
            s++;
            right++;
            c += a[right];
        } else if(s == r || right == n-1) {
            s--;
            c -= a[left];
            left++;
        } else {
            int n_right = a[right+1];
            int n_left = a[left];
            if(n_left < 0) {
                s--;
                c -= n_left;
                left++;
            } else {
                s++;
                right++;
                c += n_right;
            }
        }
        if(c > max) max = c;
        cout << c << " " << max << " " << endl;
    }
    cout << max << endl;
}
/*
Hi :)
This is my first answer around here, hope it helps.
My first intuition was to solve this problem using two pointers.
1 - Start with the sum from [0, L-1], use two variables to point to these locations and an extra one to keep track of the current subarray size.
 - Use two variables (pointers) to keep track of the subarray limits.
 - Use one variable to keep track of the current subarray size.
 - Use one variable to keep track of the current sum, and one to keep the maximum sum found.
2 - Now for every step, check if the size is equal to L or R.
 2.1 - If it's equal to L, subtract the value pointed by the lower bound pointer and add one to it.
 2.2 - If it's equal to R, add one to the upper bound pointer and add the value now pointed by it.
 2.3 - If it's not equal neither L or R, you should check if the value pointed by the lower bound pointer is negative. If it is, you definitely don't want it on the max sum, so remove it using (2.1).
       If it's positive, you should keep adding number to the subarray using (2.2).
What happens when the array only have negative values? It returns the less negative sum, it's possible to check it by hand.
 */