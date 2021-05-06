#include <bits/stdc++.h>
using namespace std;
int n, q;

int main() {

    cin >> n >> q;
    int maze[2][n];
    memset(maze, 0, sizeof(maze));
    int rb = 0;
    bool possible = true;

    for(int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;

        maze[r-1][c-1] = !maze[r-1][c-1];
        if(maze[r-1][c-1]) {
            if ((c-2) >= 0 && maze[(r % 2)][c - 2]) {
                possible = false;
                rb++;
            }
            if (maze[(r % 2)][c - 1]) {
                possible = false;
                rb++;
            }
            if (maze[(r % 2)][c] && c < n) {
                possible = false;
                rb++;
            }
        } else {
            if ((c-2) >= 0 && maze[(r % 2)][c - 2]) {
                rb--;
                if(!rb) possible = true;
            }
            if (maze[(r % 2)][c - 1]) {
                rb--;
                if(!rb) possible = true;
            }
            if (maze[(r % 2)][c] && c < n) {
                rb--;
                if(!rb) possible = true;
            }
        }
        cout << ((possible) ? "Yes" : "No") << endl;

    }

}
