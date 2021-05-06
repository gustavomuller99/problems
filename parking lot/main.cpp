#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // borders =  4 * 2 * 3 * (4 ^ (spaces to fill - 1))
    // middle = 4 * (positions to group - 2) * 3^2 * 4^(spaces to fill - 2)
    // spaces tp fill = n - 2
    // positions to group = n - 1
    // this could be solved with binary exponentiation
    unsigned long long borders = 6 * pow(4, n - 2);
    unsigned long long middle = 9 * (n - 3) * pow(4, n - 3);
    cout << borders + middle << endl;

}
